#pragma GCC optimize("Ofast,unroll-loops")
#include <cstdio>
#include <cmath>
using namespace std;

struct Pt{ float x,y; short p; };
inline float dist(const Pt&a,const Pt&b){
    return hypotf(a.x-b.x,a.y-b.y);
}
int main(){
    Pt S,F,G[22];
    scanf("%f%f%f%f",&S.x,&S.y,&F.x,&F.y);
    short M; scanf("%hd",&M);
    for(int i = 0; i < M; ++i) scanf("%f%f%hd",&G[i].x,&G[i].y,&G[i].p);
    float best = 1e18f;
    for(unsigned m = 0; m < (1u<<M); ++m){
        float d = 0;
        short pts = 0;
        const Pt*pr = &S;
        for(short i = 0; i < M; ++i){
            if(m & (1u << i)){
                d+=hypotf(pr->x-G[i].x,pr->y-G[i].y);
                pr=&G[i];
                ++pts;
            } else pts+=G[i].p;
        }
        d += hypotf(pr->x-F.x,pr->y-F.y);
        if(d + pts + 1 < best) best = d + pts + 1;
    }
    printf("%.3f", best);
    return 0;
}