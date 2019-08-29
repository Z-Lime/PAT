#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,b;
    int r[31]={};
    int num=0;
    bool flag = true;
    scanf("%d %d",&n,&b);
    do{
        r[num++] = n % b;
        n = n/b;
    }while(n!=0);
    for(int i = 0;i<num/2;i++){
        if(r[i]!=r[num-i-1]){
            flag = false;
            break;
        }
    }
    if(flag) printf("Yes\n");
    else printf("No\n");
    for(int i=num-1;i>=0;i--){
        printf("%d",r[i]);
        if(i) printf(" ");
    }
    return 0;
}
