#include <iostream>
#include<cstdio>
using namespace std;
struct stu{
char name[20];
char sex;
char id[20];
int grade;
};
int main()
{
    stu s1,s2,t;
    s1.grade = -1;
    s2.grade = 101;
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s %c %s %d",&t.name,&t.sex,&t.id,&t.grade);
        if(t.sex == 'F'&&t.grade>s1.grade) s1 = t;
        else if(t.sex == 'M' &&t.grade<s2.grade) s2 = t;
    }
    if(s1.grade!=-1){
        printf("%s %s\n",s1.name,s1.id);
    }
    else printf("Absent\n");
    if(s2.grade!=101)  printf("%s %s\n",s2.name,s2.id);
    else printf("Absent\n");
    if(s1.grade!=-1&&s2.grade!=101) printf("%d",s1.grade-s2.grade);
    else printf("NA");
    return 0;
}
