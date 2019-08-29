#include <iostream>
#include <cstdio>
#include <math.h>
#define CLK_TCK 100

using namespace std;

int main()
{
    int c1,c2;
    int r,h,m,s;
    scanf("%d%d",&c1,&c2);
    r = c2 - c1;
    if(r%100>=50) r = (r/CLK_TCK) + 1;
    else r = r/CLK_TCK;
    h = r / 3600;
    m = (r % 3600)/60;
    s = r%60;
    printf("%02d:%02d:%02d",h,m,s);
    return 0;
}
