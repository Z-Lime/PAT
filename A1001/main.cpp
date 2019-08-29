#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a,b;
    int r[7]={};
    scanf("%d %d",&a,&b);
    a = a+b;
    if(a<0){
        printf("-");
        a = a * (-1);
    }
    int num = 0;
    do{
        r[num++] = a%10;
        a = a/10;
    }while(a!=0);
    for(int i=1;i<=num;i++){
        int t = num - i;
        printf("%d",r[t]);
        if(t%3==0&&t!=0) printf(",");
    }
    return 0;
}
