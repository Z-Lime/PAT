#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#define MAX_DIGITS 15
int main()
{
    char num[MAX_DIGITS];
    string name[10];
    name[0] = "ling";
    name[1] = "yi";
    name[2] = "er";
    name[3] = "san";
    name[4] = "si";
    name[5] = "wu";
    name[6] = "liu" ;
    name[7] = "qi";
    name[8] = "ba";
    name[9] = "jiu";
    string danwei[5];
    danwei[0] = "Shi";
    danwei[1] = "Bai";
    danwei[2] = "Qian";
    danwei[3] = "Wan";
    danwei[4] = "Yi";
    scanf("%s",num);
    int len = strlen(num);
    int left = 0,right = len -1;
    if(num[0]=='-'){
        printf("Fu");
        left++;
    }
    while(left+4<=right){
        right -= 4;
    }
    while(left<len){
        bool flag = false;
        bool isprint = false;
        while(left<=right){
            if(left>0&&num[left]=='0'){
                flag = true;
            }
            else{
                if(flag){
                    cout<<" ling";
                    flag = false;
                }
                if(left>0) cout<<" ";
                cout<<name[num[left]-'0'];
                isprint = true;
                if(left != right) cout<<" "<<danwei[right-left-1];
            }
            left++;
            }
            if(isprint){
                if(right!=len-1) cout<<" "<<danwei[(len-1-right)/4+2];
            }
            right += 4;
    }
    return 0;
}
