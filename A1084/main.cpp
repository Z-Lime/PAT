#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

const int N = 90;

char orign[N];
char type_out[N];

bool exist[37]={false};

int hashFunc(char c){
    if(c>='0'&&c<='9'){
        return c-'0';
    }
    else if(c>='A'&&c<='Z'){
        return c-'A'+10;
    }
    else if(c>='a'&&c<='z'){
        return c-'a'+10;
    }
    else
        return 36;
}
int main()
{
    scanf("%s %s",&orign,&type_out);
    int leno = strlen(orign);
    int lent = strlen(type_out);

    for(int i=0;i<lent;i++){
        exist[hashFunc(type_out[i])] = true;
    }
    for(int i=0;i<leno;i++){
        int t = hashFunc(orign[i]);
        if(exist[t]==false){
            if(orign[i]>='a'&&orign[i]<='z')
                printf("%c",orign[i]-'a'+'A');
            else
                printf("%c",orign[i]);
            exist[t] = true;
        }
    }
    return 0;
}
