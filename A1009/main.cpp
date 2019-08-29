#include <cstdio>
const int k = 1005;
double a[k]={};
double r[2*k]={};

int main()
{
    int n1,n2,max1=-1,max2=-1;
    int t;
    double tf;
    scanf("%d",&n1);
    while(n1--){
      scanf("%d %lf",&t,&tf);
      a[t] = tf;
      if(max1==-1) max1 = t;
    }
    scanf("%d",&n2);
    while(n2--){
      scanf("%d %lf",&t,&tf);
      if(max2==-1) max2 = t;
      for(int i=max1;i>=0;i--)
            r[i+t] += (tf * a[i]);

    }
    int num=0;
    for(int i = max1+max2;i>=0;i--){
        if(r[i]!=0.0)num++;
    }
    printf("%d",num);
    for(int i = max1+max2;i>=0;i--){
        if(r[i]!=0){
            printf(" %d %.1f",i,r[i]);
        }
    }
    return 0;
}
