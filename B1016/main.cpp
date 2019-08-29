#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char a[10]={0},b[10]={0};
    long long da=0,db=0,r1=0,r2=0,k1=1,k2=1;
    scanf("%s %ld %s %ld",&a,&da,&b,&db);
    for(int i=0;i<10;i++){
        if(a[i]==(da+'0')){
            r1 = r1 + da*k1 ;
            k1 = k1 * 10;
        }
        if(b[i]==(db+'0')){
            r2 = r2 + db*k2;
            k2 = k2 * 10;
        }
    }
    printf("%ld",r1+r2);
    return 0;
}
