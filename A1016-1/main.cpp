#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#define N 1005
#define RateNum 24
using namespace std;
struct Node{
    char id[25];
    int time[4];
    bool on;
};

const char on_line[10] = {"on-line"};
Node record[N];
int rate[RateNum];

bool cmp(Node a,Node b){
    int flag = strcmp(a.id,b.id);
    if(flag<0){
        return true;
    }
    else if(flag>0){
        return false;
    }
    else{
        if(a.time[0]!=b.time[0]) return a.time[0]<b.time[0];
        if(a.time[1]!=b.time[1]) return a.time[1]<b.time[1];
        if(a.time[2]!=b.time[2]) return a.time[2]<b.time[2];
        if(a.time[3]!=b.time[3]) return a.time[3]<b.time[3];
    }
}
void get_ans(int on, int off, int &time, int &money){
    Node temp1 = record[on];
    while(temp1.time[1]<record[off].time[1]||temp1.time[2]<record[off].time[2]||temp1.time[3]<record[off].time[3]){
        time++;
        temp1.time[3]++;
        money += rate[temp1.time[2]];
        if(temp1.time[3]==60){
            temp1.time[3] = 0;
            temp1.time[2]++;
        }
        if(temp1.time[2]==24){
            temp1.time[2] = 0;
            temp1.time[1]++;
        }
    }
}
int main()
{
    int n;
    for(int i=0;i<RateNum;i++){
        scanf("%d",&rate[i]);
    }
    scanf("%d",&n);
    char line_flag[10];
    for(int i=0;i<n;i++){
        scanf("%s %d:%d:%d:%d %s",&record[i].id,
              &record[i].time[0],&record[i].time[1],
              &record[i].time[2],&record[i].time[3],&line_flag);
        if(strcmp(line_flag,on_line)==0) record[i].on = true;
        else record[i].on = false;

    }
    sort(record,record+n,cmp);
    int on=0,off,next;
    while(on<n){
        int printflag = 0;
        next = on;
        while(next<n&&strcmp(record[next].id,record[on].id)==0){
            if(printflag==0&&record[next].on == true){
                printflag = 1;
            }
            else if(printflag==1&&record[next].on == false){
                printflag = 2;
            }
            next++;
        }
        if(printflag<2){
            on = next;
            continue;
        }
        int totalcost = 0;
        printf("%s %02d\n",record[on].id,record[on].time[0]);
        while(on<next){
            while(on<(next-1)&&(record[on].on!=true||record[on+1].on!=false)){on++;}
            off = on + 1;
            if(off == next){
                on = next;
                break;
            }
            printf("%02d:%02d:%02d %02d:%02d:%02d ",record[on].time[1],record[on].time[2],
                   record[on].time[3],record[off].time[1],record[off].time[2],record[off].time[3]);
            int time=0,money=0;
            get_ans(on,off,time,money);
            totalcost += money;
            printf("%d $%.2f\n",time,money/100.0);
            on = off + 1;
        }
        printf("Total amount: $%.2f\n",totalcost/100.0);
    }
    return 0;
}
