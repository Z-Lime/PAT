#include <iostream>
#include <string.h>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Student{
    int id;
    char name[10];
    int grade;
};

const int N=100005;
Student stu[N];

bool cmp_id(Student a,Student b){
    return a.id<b.id;
}
bool cmp_name(Student a,Student b){
    int t = strcmp(a.name,b.name);
    if(t==0)    return a.id<b.id;
    else return t<0;
}
bool cmp_grade(Student a,Student b){
    if(a.grade!=b.grade) return a.grade<b.grade;
    else return a.id<b.id;
}
int main()
{
    int n,column;
    scanf("%d %d",&n,&column);
    for(int i=0;i<n;i++){
        scanf("%d %s %d",&stu[i].id,&stu[i].name,&stu[i].grade);
    }
    switch(column){
    case 1:
        sort(stu,stu+n,cmp_id);
        break;
    case 2:
        sort(stu,stu+n,cmp_name);
        break;
    case 3:
        sort(stu,stu+n,cmp_grade);
        break;
    }
    for(int i=0;i<n;i++){
        printf("%06d %s %d",stu[i].id,stu[i].name,stu[i].grade);
        if(i!=n-1) printf("\n");
    }
    return 0;
}
