#include <iostream>
#define N 100005
using namespace std;

int a[N],dis[N];
int main()
{
    int n;
    int sum=0;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        sum += a[i];
        dis[i] = sum;
    }
    int tn;
    cin>>tn;
    while(tn--){
        int l,r;
        cin>>l>>r;
        int temp = l;
        if(l>r){
            l = r;
            r = temp;
        }
        int r1,r2;
        r1 = dis[r-1] - dis[l-1];
        r2 = sum - r1;
        cout<<min(r1,r2);
        if(tn!=0) cout<<endl;
    }
    return 0;
}
