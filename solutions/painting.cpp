// Author: H. Hristov
#include <iostream>
using namespace std;

int cubes[7];
int main() {
    short w, l, h, k;
    cin >> w >> l >> h >> k;
    if(w == l == h == 1) {
        cubes[6] = 1;
    }
    if ((w == 1) != (h == 1) != (l == 1)) {
        cubes[4] = 4;
        cubes[3] = max(0, 2*(w-2)) + max(0, 2*(h-2)) + max(0, 2*(l-2));
        cubes[2] = w*h*l - (cubes[4] + cubes[3]);
    }
    else if (w != 1 && h!=1 && l !=1) {
        cubes[3] = 8;
        cubes[2] = (h-2)*4 + (w-2)*4 + (l-2)*4;
        cubes[1] = ((w*h - ((w << 1) + (h << 1) - 4)) << 1) +
                   ((w*l - ((w << 1) + (l << 1) - 4)) << 1) +
                   ((h*l - ((h << 1) + (l << 1) - 4)) << 1);
        cubes[0] = w*l*h - (cubes[3] + cubes[2] + cubes[1]);
    } else {
        cubes[5] = 2;
        cubes[4] = max(w, max(l, h)) - 2;
    }

    cout << cubes[k];
    return 0;
}