#include <cstdio>
#define k 1005
using namespace std;
double x[k] ={};
int main()
{
    int n1,n2,max1=-1,max2=-1;
    scanf("%d",&n1);
    while(n1--){
        int t;
        scanf("%d",&t);
        if(max1==-1) max1 = t;
        double tf;
        scanf("%lf",&tf);
        x[t] = x[t] + tf;
    }
    scanf("%d",&n2);
    while(n2--){
        int t;
        scanf("%d",&t);
        if(max2==-1) max2 = t;
        double tf;
        scanf("%lf",&tf);
        x[t] = x[t] + tf;
    }
    max1 = max1>max2?max1:max2;
    int num=0;
    for(int i=max1;i>=0;i--){
        if (x[i]!=0 ) num++;
    }
    printf("%d",num);
    for(int i=max1;i>=0;i--){
        if (x[i] != 0){
            printf(" %d %.1f",i,x[i]);
        }
    }
    return 0;
}
