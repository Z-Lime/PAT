#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a1=0,a2=0,a3=0,a5=0;
    float a4 = 0.0;
    int n;
    int flag = 1;
    int c1=0,c2=0,c3=0,c4=0,c5=0;
    scanf("%d",&n);
    while(n--)
    {
        int t;
        scanf("%d",&t);
        switch(t%5){
    case 0:
        if(t%2==0) {
            a1 += t;
            c1++;
            }
        break;
    case 1:
        a2 = a2 + flag*t;
        flag = flag*(-1);
        c2++;
        break;
    case 2:
        a3++;
        c3++;
        break;
    case 3:
        a4 += t;
        c4 ++;
        break;
    case 4:
        if(t>a5) {
            a5 = t;
            c5++;
            }
        break;
    default:
        break;
        }
    }
    if(c1==0) printf("N ");
    else printf("%d ",a1);
    if(c2==0) printf("N ");
    else printf("%d ",a2);
    if(c3==0) printf("N ");
    else printf("%d ",a3);
    if(c4==0) printf("N ");
    else printf("%.1f ",(double)a4/c4);
    if(c5==0) printf("N");
    else printf("%d",a5);
    return 0;
}
