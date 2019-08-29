#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a[3],b[3],r[3];
    scanf("%d.%d.%d",&a[0],&a[1],&a[2]);
    scanf("%d.%d.%d",&b[0],&b[1],&b[2]);
    r[2] = (a[2] + b[2])%29;
    int t = (a[2] + b[2])/29;
    t += a[1] + b[1];
    r[1] = t % 17;
    r[0] = t/17 + a[0] + b[0];
    for(int i=0;i<3;i++){
        printf("%d",r[i]);
        if(i!=2) printf(".");
    }
    return 0;
}
