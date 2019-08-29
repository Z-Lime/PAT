#include <iostream>

using namespace std;

int main()
{
    int n;
    long long a,b,c,r;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        r=a+b;
        cout<<"Case #"<<i<<": ";
        if(a>0&&b>0&&r<0)
            cout<<"true";
        else if(a<0&&b<0&&r>=0)
            cout<<"false";
        else if(r>c)
           cout<<"true";
        else
            cout<<"false";
        cout<<endl;
    }
    return 0;
}
