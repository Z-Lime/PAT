#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    int ay=0,ap=0,as=0;
    int by=0,bp=0,bs=0;
    int ac=0,aj=0,ab=0;
    int bc=0,bj=0,bb=0;
    while(n--){
        char a,b;
        scanf("%c %c",&a,&b);
        getchar();
        if(a==b){
            ap++;
            bp++;
        }
        else if(a=='C'&&b=='J'){
            ay++;
            bs++;
            ac++;
        }
        else if(a=='J'&&b=='B'){
            ay++;
            bs++;
            aj++;
        }
        else if(a=='B'&&b=='C'){
            ay++;
            bs++;
            ab++;
        }
        else if(a=='C'&&b=='B')
        {
            as++;
            by++;
            bb++;
        }
        else if(a=='J'&&b=='C'){
            as++;
            by++;
            bc++;
        }
        else if(a=='B'&&b=='J'){
            as++;
            by++;
            bj++;
        }
    }
    printf("%d %d %d\n",ay,ap,as);
    printf("%d %d %d\n",by,bp,bs);
    if(ab>=ac&&ab>=aj)printf("B ");
    else if(ac>ab&&ac>=aj)printf("C ");
    else printf("J ");
    if(bb>=bc&&bb>=bj)printf("B");
    else if(bc>bb&&bc>=bj)printf("C");
    else printf("J");
    return 0;
}
