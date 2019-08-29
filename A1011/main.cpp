#include <cstdio>
#define k 3

void print(int x){
    switch(x){
    case 0:printf("W ");
            break;
    case 1:printf("T ");
            break;
    case 2:printf("L ");
            break;
    default:break;
    }
}

int main()
{
    double a=0,b=0,c=0,t;
    int x,y,z;
    for(int m=0;m<k;m++){
        scanf("%lf",&t);
        if(t>a){
            a = t;
            x = m;
        }
    }
    for(int m=0;m<k;m++){
        scanf("%lf",&t);
        if(t>b){
            b = t;
            y = m;
        }
    }
    for(int m=0;m<k;m++){
        scanf("%lf",&t);
        if(t>c){
            c = t;
            z = m;
        }
    }
    print(x);
    print(y);
    print(z);
    t = ((a*b*c*0.65)-1)*2;
    printf("%.2f",t);
    return 0;
}
