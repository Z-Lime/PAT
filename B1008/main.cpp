#include <iostream>
#include <cstdio>
#define N 100
using namespace std;

int main()
{
    int a[N]={0};
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int t = (i + m)%n;
        scanf("%d",&a[t]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
        if(i<n-1) printf(" ");
    }
    return 0;
}
