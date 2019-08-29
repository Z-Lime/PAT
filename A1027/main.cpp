#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a[3];
    char radix[3] = {'A','B','C'};
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    printf("#");
    for(int i=0;i<3;i++){
        int t2=a[i]%13;
        int t1 = (a[i] - t2)/13;
        if(t1 > 9) printf("%c",radix[t1-10]);
        else printf("%d",t1);
        if(t2 > 9) printf("%c",radix[t2-10]);
        else printf("%d",t2);
    }

    return 0;
}
