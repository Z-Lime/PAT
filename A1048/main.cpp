#include <iostream>
#include <cstdio>

using namespace std;

const int N = 100005;
int coin[N];

int main()
{
    int n,value;
    bool flag = false;
    scanf("%d %d",&n,&value);
    for(int i=0,t;i<n;i++){
        scanf("%d",&t);
        coin[t] ++;
    }
    int t = value/2;
    for(int i=1;i<=t;i++){
        if(coin[i]&&coin[value-i]){
            if(i!=value-i||coin[i]>1){
                printf("%d %d",i,value-i);
                flag = true;
                break;
            }
        }
    }
    if(flag==false){
        printf("No Solution");
    }
    return 0;
}
