#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    int cnt1=0,cnt2=0;
    scanf("%d",&n);
    while(n--){
       int a1,a2,b1,b2;
       scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
       int t = a1 + b1;
       if(t==a2 && t!=b2) cnt2++;
       if(t!=a2 && t==b2) cnt1++;
    }
    printf("%d %d",cnt1,cnt2);
    return 0;
}
