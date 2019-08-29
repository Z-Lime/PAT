#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

struct Person{
    char name[10];
    int age;
    int worth;
};

const int N=100005;
Person per[N];

bool cmp(Person a, Person b){
    if(a.worth!=b.worth) return a.worth>b.worth;
    if(a.age!=b.age) return a.age<b.age;
    return (strcmp(a.name,b.name))<0;

}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%s %d %d",&per[i].name,&per[i].age,&per[i].worth);
    }
    sort(per,per+n,cmp);
    for(int i=0;i<k;i++){
        int num=0,left=0,right=0,cnt=0;
        scanf("%d %d %d",&num,&left,&right);
        printf("Case #%d:\n",i+1);
        for(int j=0;j<n&&num>0;j++){
            if(per[j].age>=left&&per[j].age<=right){
                printf("%s %d %d\n",per[j].name,per[j].age,per[j].worth);
                num--;
                cnt++;
            }
        }
        if(cnt==0) printf("None\n");
    }
    return 0;
}
