#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
struct Node{
    char id[11];
    char pwd[11];
    bool ischange;
};
Node info[1005];
bool modify(char (&a)[11]){
   int len = strlen(a);
   bool flag = false;
   for(int i=0;i<len;i++){
    switch(a[i]){
    case 'l' :
        a[i] = 'L';
        flag = true;
        break;
    case '1' :
        a[i] = '@';
        flag = true;
        break;
    case 'O' :
        a[i] = 'o';
        flag = true;
        break;
    case '0' :
        a[i] = '%';
        flag = true;
        break;
    default:
        break;
    }
   }
   return flag;
}

int main()
{
    int n,num=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>info[i].id>>info[i].pwd;
    }
    for(int i=0;i<n;i++){
        info[i].ischange = modify(info[i].pwd);
        if(info[i].ischange) num++;
    }
    if(num==0&&n==1){
        printf("There is 1 account and no account is modified");
    }
    else if(num==0){
        printf("There are %d accounts and no account is modified",n);
    }
    else{
        printf("%d\n",num);
        for(int i=0;i<n;i++){
            if(info[i].ischange){
                printf("%s %s",info[i].id,info[i].pwd);
                num--;
                if(num!=0) printf("\n");
            }
        }
    }
    return 0;
}
