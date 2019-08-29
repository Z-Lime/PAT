#include <iostream>
#include <algorithm>
#include <string.h>
#define N 100005
using namespace std;

struct Node{
    int id;
    int vg;
    int tg;
};
Node man0[N];
Node man1[N];
Node man2[N];
Node man3[N];
bool cmp(Node a,Node b){
    int t1 = a.tg + a.vg,t2 = b.tg+b.vg;
    if(t1!=t2)return t1>t2;
    else if(a.vg!=b.vg)return a.vg>b.vg;
    else return a.id<b.id;
}
int main()
{
    int n,a,b;
    int c0=0,c1=0,c2=0,c3=0;
    cin>>n>>a>>b;
    Node temp;
    for(int i=0;i<n;i++){
        cin>>temp.id>>temp.vg>>temp.tg;
        if(temp.vg>=a&&temp.tg>=a){
            if(temp.vg>=b&&temp.tg>=b) man0[c0++] = temp;
            else if(temp.vg>=b&&temp.tg<b) man1[c1++] = temp;
            else if(temp.vg<b&&temp.tg<b&&temp.vg>=temp.tg) man2[c2++] = temp;
            else man3[c3++] = temp;
        }
    }
    sort(man0,man0+c0,cmp);
    sort(man1,man1+c1,cmp);
    sort(man2,man2+c2,cmp);
    sort(man3,man3+c3,cmp);
    int num = c0+c1+c2+c3;
    cout<<num;
    if(num!=0) cout<<endl;
    for(int i=0;i<c0;i++){
        cout<<man0[i].id<<" "<<man0[i].vg<<" "<<man0[i].tg;
        num--;
        if(num!=0) cout<<endl;
    }
    for(int i=0;i<c1;i++){
        cout<<man1[i].id<<" "<<man1[i].vg<<" "<<man1[i].tg;
        num--;
        if(num!=0) cout<<endl;
    }
    for(int i=0;i<c2;i++){
        cout<<man2[i].id<<" "<<man2[i].vg<<" "<<man2[i].tg;
        num--;
        if(num!=0) cout<<endl;
    }
    for(int i=0;i<c3;i++){
        cout<<man3[i].id<<" "<<man3[i].vg<<" "<<man3[i].tg;
        num--;
        if(num!=0) cout<<endl;
    }
    return 0;
}
