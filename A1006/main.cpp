#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct Node{
    char id[20];
    int hh,mm,ss;
};
bool great(Node n1,Node n2){
    if(n1.hh>n2.hh) return true;
    else if(n1.hh==n2.hh&&n1.mm>n2.mm) return true;
    else if(n1.hh==n2.hh&&n1.mm==n2.mm&&n1.ss>n2.ss) return true;
    else return false;
}
int main()
{
    int n;
    Node a,b,t;
    a.hh = 24;a.mm=60;a.ss=60;
    b.hh = 0;a.mm=0; a.ss=0;
    scanf("%d",&n);
    while(n--){
        scanf("%s %d:%d:%d",&t.id,&t.hh,&t.mm,&t.ss);
        if(great(a,t)) a = t;
        scanf("%d:%d:%d",&t.hh,&t.mm,&t.ss);
        if(great(t,b)) b = t;
    }
    printf("%s %s",a.id,b.id);
    return 0;
}
