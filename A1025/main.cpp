#include <iostream>
#include <algorithm>
#include <string.h>
#define N 105
using namespace std;
struct Node{
    char id[14];
    int score;
    int final_rank;
    int location_number;
    int local_rank;
};
Node numbers[30005];
int a[N];
bool cmp(Node a,Node b){
    if(a.score!=b.score)    return a.score>b.score;
    else return strcmp(a.id,b.id)<0;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int j;
        cin>>j;
        a[i] = a[i-1] + j;
        for(int k=a[i-1];k<a[i];k++){
            cin>>numbers[k].id>>numbers[k].score;
            numbers[k].location_number = i;
        }
        sort(numbers+a[i-1],numbers+a[i],cmp);
        numbers[a[i-1]].local_rank = 1;
        for(int k=a[i-1]+1,t=0;k<a[i];k++){
                if(numbers[k].score == numbers[k-1].score){
                     numbers[k].local_rank = numbers[k-1].local_rank;
                     t++;
                }
                else{
                    numbers[k].local_rank = numbers[k-1].local_rank + 1+t;
                    t = 0;
                }
        }
    }
    sort(numbers,numbers+a[n],cmp);
    numbers[0].final_rank = 1;
    cout<<a[n]<<endl;
    cout<<numbers[0].id<<" "<<numbers[0].final_rank<<" "<<numbers[0].location_number<<" "<<numbers[0].local_rank;
    if(a[n]>1) cout<<endl;
    for(int k=1,t=0;k<a[n];k++){
        if(numbers[k].score == numbers[k-1].score){
             numbers[k].final_rank = numbers[k-1].final_rank;
             t++;
        }
        else{
            numbers[k].final_rank = numbers[k-1].final_rank + 1+t;
            t = 0;
        }
        cout<<numbers[k].id<<" "<<numbers[k].final_rank<<" "<<numbers[k].location_number<<" "<<numbers[k].local_rank;
        if(k!=a[n]-1) cout<<endl;
    }
    return 0;
}
