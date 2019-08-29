#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXSIZE=85;
char str[MAXSIZE];
int main()
{
    scanf("%s",str);
    int l=strlen(str);
    int n,c;
    n = (l+2)/3;
    c = l - 2*n;
    for(int i=0;i<n-1;i++)
    {
        printf("%c",str[i]);
        for(int j=0;j<c;j++)
            printf(" ");
        printf("%c\n",str[l-1-i]);
    }
    for(int i=n-1;i<=l-n;i++)
        printf("%c",str[i]);
    return 0;
}
