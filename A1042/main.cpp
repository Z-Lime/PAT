#include <iostream>

using namespace std;
#define N 54
void printcard(int a[]);
int main()
{
    int n;
    int index[N],a[N],b[N];
    cin>>n;
    for(int k=0;k<N;k++){
        cin>>index[k];
        a[k] = k + 1;
    }
    for(int i=1;i<=n;i++){
        int t;
        if(i%2){
            for(int j=0;j<N;j++){
                t = index[j] - 1;
                b[t] = a[j];
            }
        }
        else{
            for(int j=0;j<N;j++){
                t = index[j] - 1;
                a[t] = b[j];
            }
        }
    }
    if(n%2){
        printcard(b);
    }
    else{
        printcard(a);
    }
    return 0;
}
void printcard(int a[]){
    for(int i=0;i<N;i++){
        if(a[i]<=13)
            cout<<"S"<<a[i];
        else if(a[i]<=26)
            cout<<"H"<<a[i]-13;
        else if (a[i]<=39)
            cout<<"C"<<a[i]-26;
        else if(a[i]<=52)
            cout<<"D"<<a[i]-39;
        else
            cout<<"J"<<a[i]-52;

        if(i!=N-1) cout<<" ";
    }
}
