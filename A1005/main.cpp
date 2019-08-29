#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    int i=0,t=0;
    char c;
    string output[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int r[4];
    scanf("%c",&c);
    while(c!='\n'){
        i = i + (c -'0');
        scanf("%c",&c);
    }
    t = 0;
    do{
        r[t++] = i%10;
        i = i/10;
    }while(i!=0);
    for(int j = 0;j<t;j++)
    {
        cout<<output[r[t-1-j]];
        if(j!=t-1) printf(" ");
    }

    return 0;
}
