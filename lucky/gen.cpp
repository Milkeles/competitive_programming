#include <bits/stdc++.h>
using namespace std;

// BigInt as vector of digits in some base, or we just work with strings + __int128 / Python-style big mul
// Since LCM of 6 numbers <= 49 fits in long long, and we need numbers up to 10^100,
// we represent big numbers as strings in base B and do mod via Horner's method.

const string DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

// Convert decimal string -> remainder mod m (m fits in long long)
long long modDecStr(const string& s, long long m) {
    long long r = 0;
    for (char c : s) r = (r * 10 + (c - '0')) % m;
    return r;
}

// Multiply big decimal string by k, return decimal string
string mulDec(const string& s, long long k) {
    long long carry = 0;
    string res = s;
    for (int i = res.size()-1; i >= 0; i--) {
        long long cur = (long long)(res[i]-'0') * k + carry;
        res[i] = '0' + cur % 10;
        carry = cur / 10;
    }
    string prefix = "";
    while (carry) { prefix += char('0' + carry % 10); carry /= 10; }
    reverse(prefix.begin(), prefix.end());
    return prefix + res;
}

// Add long long to big decimal string
string addDec(const string& s, long long v) {
    string res = s;
    long long carry = v;
    for (int i = res.size()-1; i >= 0 && carry; i--) {
        long long cur = (res[i]-'0') + carry;
        res[i] = '0' + cur % 10;
        carry = cur / 10;
    }
    string prefix = "";
    while (carry) { prefix += char('0' + carry % 10); carry /= 10; }
    reverse(prefix.begin(), prefix.end());
    return prefix + res;
}

// Compare decimal strings (both trimmed, no leading zeros except "0")
int cmpDec(const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() < b.size() ? -1 : 1;
    return a < b ? -1 : (a == b ? 0 : 1);
}

// base^exp as decimal string
string powDec(long long base, int exp) {
    string r = "1";
    for (int i = 0; i < exp; i++) r = mulDec(r, base);
    return r;
}

// Convert base-B string to decimal string
string baseToDecStr(const string& s, int base) {
    string r = "0";
    for (char c : s) {
        r = mulDec(r, base);
        int d = DIGITS.find(c);
        r = addDec(r, d);
    }
    return r;
}

// Convert decimal string to base-B string
string decToBase(string dec, int base) {
    if (dec == "0") return "0";
    string result = "";
    while (dec != "0" && dec != "") {
        // dec % base
        long long rem = 0;
        string next = "";
        for (char c : dec) {
            rem = rem * 10 + (c - '0');
            if (!next.empty() || rem / base > 0)
                next += char('0' + rem / base);
            rem %= base;
        }
        result += DIGITS[rem];
        dec = next.empty() ? "0" : next;
    }
    reverse(result.begin(), result.end());
    return result;
}

long long gcd(long long a, long long b) { return b ? gcd(b, a%b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a,b) * b; }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// Generate a random big decimal string in [lo_dec, hi_dec] that is divisible by L
// lo_dec, hi_dec are decimal strings
// Strategy: pick random k in [ceil(lo/L), floor(hi/L)], return k*L
// We do this by: k_lo = (lo + L - 1) / L, k_hi = hi / L (big integer division by small L)
string divDec(const string& s, long long d) {
    // returns floor(s / d) as decimal string
    string result = "";
    long long rem = 0;
    for (char c : s) {
        rem = rem * 10 + (c - '0');
        result += char('0' + rem / d);
        rem %= d;
    }
    // strip leading zeros
    int start = 0;
    while (start < (int)result.size()-1 && result[start] == '0') start++;
    return result.substr(start);
}

// Subtract big decimal strings: a - b, assuming a >= b
string subDec(const string& a, const string& b) {
    string res = a;
    int borrow = 0;
    int i = res.size() - 1, j = b.size() - 1;
    for (; i >= 0; i--, j--) {
        int d = (res[i] - '0') - borrow - (j >= 0 ? b[j] - '0' : 0);
        if (d < 0) { d += 10; borrow = 1; } else borrow = 0;
        res[i] = '0' + d;
    }
    int start = 0;
    while (start < (int)res.size()-1 && res[start] == '0') start++;
    return res.substr(start);
}

string randMultipleInRange(const string& lo, const string& hi, long long L) {
    string k_lo = divDec(lo, L);
    {
        string check = mulDec(k_lo, L);
        if (cmpDec(check, lo) < 0) k_lo = addDec(k_lo, 1);
    }
    string k_hi = divDec(hi, L);

    if (cmpDec(k_lo, k_hi) > 0) return ""; // no multiple in range

    // Compute range = k_hi - k_lo, clamp to 1e18 for random offset
    string range = subDec(k_hi, k_lo);
    long long offset;
    const string CAP = "1000000000000000000";
    if (cmpDec(range, CAP) <= 0) {
        long long r = 0;
        for (char c : range) r = r * 10 + (c - '0');
        offset = (long long)(rng() % (unsigned long long)(r + 1));
    } else {
        offset = (long long)(rng() % 1000000000000000000ULL);
    }
    return mulDec(addDec(k_lo, offset), L);
}

// Generate number with exactly `digits` digits in base B, divisible by L
// Returns base-B string, or "" on failure
string genMultiple(int base, int digits, long long L) {
    // lo = base^(digits-1), hi = base^digits - 1
    string lo = digits == 1 ? "1" : powDec(base, digits-1);
    string hi = addDec(powDec(base, digits), -1); // base^digits - 1
    // wait, addDec doesn't support negative. do it manually:
    // hi = powDec(base, digits) then subtract 1
    {
        string tmp = powDec(base, digits);
        // subtract 1: find last digit, decrement with borrow
        hi = tmp;
        int i = hi.size()-1;
        while (i >= 0 && hi[i] == '0') { hi[i] = '9'; i--; }
        if (i >= 0) hi[i]--;
        // strip leading zero if any
        if (hi.size() > 1 && hi[0] == '0') hi = hi.substr(1);
    }

    string dec = randMultipleInRange(lo, hi, L);
    if (dec.empty()) return "";
    return decToBase(dec, base);
}

// Generate number with exactly `digits` digits in base B, NOT divisible by L
string genNonMultiple(int base, int minDigits, int maxDigits, long long L) {
    // Pick a random digit count in [minDigits, maxDigits]
    int digits = minDigits + (int)(rng() % (maxDigits - minDigits + 1));

    string lo = digits == 1 ? "1" : powDec(base, digits - 1);
    string hi;
    {
        string tmp = powDec(base, digits);
        hi = tmp;
        int i = hi.size()-1;
        while (i >= 0 && hi[i] == '0') { hi[i] = '9'; i--; }
        if (i >= 0) hi[i]--;
        if (hi.size() > 1 && hi[0] == '0') hi = hi.substr(1);
    }

    // Compute range size, clamp to 1e18
    string range = subDec(hi, lo);
    const string CAP = "1000000000000000000";
    long long offset;
    if (cmpDec(range, CAP) <= 0) {
        long long r = 0;
        for (char c : range) r = r * 10 + (c - '0');
        offset = (long long)(rng() % (unsigned long long)(r + 1));
    } else {
        offset = (long long)(rng() % 1000000000000000000ULL);
    }
    string dec = addDec(lo, offset);

    // Shift off any multiple of L
    long long rem = modDecStr(dec, L);
    if (rem == 0) {
        // nudge by 1, wrap around if it exceeds hi
        dec = addDec(dec, 1);
        if (cmpDec(dec, hi) > 0) dec = lo; // lo itself — check below
        rem = modDecStr(dec, L);
    }
    if (rem != 0) return decToBase(dec, base);

    // Absolute fallback: scan from lo
    for (long long v = 1; v <= L + 1; v++) {
        string candidate = addDec(lo, v);
        if (cmpDec(candidate, hi) > 0) break;
        if (modDecStr(candidate, L) != 0) return decToBase(candidate, base);
    }
    // If all in range are multiples (extremely rare), just return lo+1 regardless of range
    return decToBase(addDec(lo, 1), base);
}

int main() {
    int day, n, minDigits, maxDigits, winStart, winLen;
    long long ys[6];

    cout << "Day of month (1-31): ";                  cin >> day;
    cout << "Total numbers n: ";                      cin >> n;
    cout << "Min digits per lucky number (base B): "; cin >> minDigits;
    cout << "Max digits per lucky number (base B): "; cin >> maxDigits;
    cout << "Lucky window start (1-indexed): ";       cin >> winStart;
    cout << "Lucky window length: ";                  cin >> winLen;
    cout << "6 lotto numbers (1-49): ";
    for (int i = 0; i < 6; i++) cin >> ys[i];

    int base = day * 2;
    if (base < 2 || base > 62) { cerr << "Base " << base << " out of [2,62]\n"; return 1; }
    if (winStart < 1 || winStart + winLen - 1 > n) { cerr << "Window out of range\n"; return 1; }
    if (minDigits < 1 || minDigits > maxDigits) { cerr << "minDigits must be >= 1 and <= maxDigits\n"; return 1; }

    long long L = 1;
    for (int i = 0; i < 6; i++) L = lcm(L, ys[i]);

    cerr << "Base B = " << base << ", LCM = " << L << "\n";
    cerr << "Lucky window: [" << winStart << ", " << winStart+winLen-1 << "]\n";
    cerr << "Expected output: " << winStart << " " << winStart+winLen-1 << "\n";

    ofstream fout("test.in");
    if (!fout) { cerr << "Failed to open test.in\n"; return 1; }

    fout << n << " " << day << "\n";

    for (int i = 1; i <= n; i++) {
        bool inWindow = (i >= winStart && i < winStart + winLen);
        string s;
        if (inWindow) {
            s = genMultiple(base, maxDigits, L);
            if (s.empty()) {
                cerr << "Failed to generate multiple for position " << i << "\n";
                return 1;
            }
        } else {
            // Non-lucky: up to maxDigits-1 so they can't beat the window length
            int nonMax = max(1, maxDigits - 1);
            int nonMin = min(minDigits, nonMax);
            s = genNonMultiple(base, nonMin, nonMax, L);
        }
        fout << s;
        if (i < n) fout << " ";
    }
    fout << "\n";

    for (int i = 0; i < 6; i++) fout << ys[i] << " \n"[i==5];

    return 0;
}