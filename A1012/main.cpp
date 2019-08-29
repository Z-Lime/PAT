#include <iostream>
#include <algorithm>
#include <string.h>
#define N 2005
using namespace std;
struct Node{
    char id[10];
    int C;
    int M;
    int E;
    int A;
    int CRank;
    int MRank;
    int ERank;
    int ARank;
};
Node stu[N];
bool CmpA(Node a,Node b){
    return a.A>b.A;
}
bool CmpC(Node a,Node b){
    return a.C>b.C;
}
bool CmpM(Node a,Node b){
    return a.M>b.M;
}
bool CmpE(Node a,Node b){
    return a.E>b.E;
}
int CmpR(Node a){
    int i=1;
    int maxr = a.ARank;
    if(a.CRank<maxr){
        i = 2;
        maxr = a.CRank;
    }
    if(a.MRank<maxr){
        i = 3;
        maxr = a.MRank;
    }
    if(a.ERank<maxr){
        i = 4;
        maxr = a.ERank;
    }
    return i;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>stu[i].id>>stu[i].C>>stu[i].M>>stu[i].E;
        stu[i].A = (stu[i].C+stu[i].M+stu[i].E)/3;
    }
    sort(stu,stu+n,CmpA);
    for(int i=0;i<n;i++){
        if(i==0) stu[i].ARank = 1;
        else{
            if(stu[i].A==stu[i-1].A)
                stu[i].ARank = stu[i-1].ARank;
            else
                stu[i].ARank = i+1;
        }
    }
    sort(stu,stu+n,CmpC);
    for(int i=0;i<n;i++){
        if(i==0) stu[i].CRank = 1;
        else{
            if(stu[i].C==stu[i-1].C)
                stu[i].CRank = stu[i-1].CRank;
            else
                stu[i].CRank = i+1;
        }
    }
    sort(stu,stu+n,CmpM);
    for(int i=0;i<n;i++){
        if(i==0) stu[i].MRank = 1;
        else{
            if(stu[i].M==stu[i-1].M)
                stu[i].MRank = stu[i-1].MRank;
            else
                stu[i].MRank = i+1;
        }
    }
    sort(stu,stu+n,CmpE);
    for(int i=0;i<n;i++){
        if(i==0) stu[i].ERank = 1;
        else{
            if(stu[i].E==stu[i-1].E)
                stu[i].ERank = stu[i-1].ERank;
            else
                stu[i].ERank = i+1;
        }
    }
    for(int i=0;i<m;i++){
        char id[10];
        bool flag = false;
        cin>>id;
        for(int j=0;j<n;j++){
            if(strcmp(id,stu[j].id)==0){
                flag = true;
                int t = CmpR(stu[j]);
                switch(t){
                case 1:
                    cout<<stu[j].ARank<<" A";
                    break;
                case 2:
                    cout<<stu[j].CRank<<" C";
                    break;
                case 3:
                    cout<<stu[j].MRank<<" M";
                    break;
                case 4:
                    cout<<stu[j].ERank<<" E";
                    break;
                }
            }
        }
        if(flag==false) cout<<"N/A";
        if(i!=m-1) cout<<endl;
    }
    return 0;
}
