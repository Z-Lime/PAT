#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=100;
char a[N][260];

void reverse_line(char (&a)[260],int len){
    for(int i=0;i<len/2;i++){
        char c = a[i];
        a[i] = a[len-i-1];
        a[len-i-1] = c;
    }
}
int main()
{
    int n,cnt=0,min_len=260;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        fgets(a[i],260,stdin);
        int len = strlen(a[i]);
        if(a[i][len-1]=='\n'){
            a[i][len-1] = '\0';
            len--;
        }
        reverse_line(a[i],len);
        min_len = len<min_len?len:min_len;
    }
    for(int i=0;i<min_len;i++){
        char c = a[0][i];
        bool flag = true;
        for(int j=1;j<n;j++){
            if(c != a[j][i]){
                flag = false;
                break;
            }
        }
        if(flag) cnt++;
        else break;
    }
    if(cnt){
        for(int i=cnt-1;i>=0;i--){
            printf("%c",a[0][i]);
        }
    }
    else{
        printf("nai");
    }
    return 0;
}
