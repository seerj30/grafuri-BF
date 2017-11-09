#include <iostream>
#include <fstream>
using namespace std;

void bf(int vf,int viz[],int n,int a[50][50])
{
    int c[50],p,u,k;
    p=u=1;
    c[p]=vf;
    viz[vf]=1;
    while(p<=u)
    {
        for(k=1;k<=n;k++)
            if(a[c[p]][k]==1 && viz[k]==0)
            {
                c[++u]=k;
                viz[k]=1;
            }
            p++;
    }
    for(k=1;k<=u;k++)
        cout<<c[k]<<" ";
}

void citire(int &n,int a[50][50])
{
    int i,j;
    ifstream f("in.txt");
    f>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            f>>a[i][j];
}

int main()
{
    int n,a[50][50],viz[50],vf;
	cout<<"vf=";cin>>vf;
    citire(n,a);
    for(int i=1;i<=n;i++)
        viz[i]=0;
    bf(vf,viz,n,a);
    return 0;
}
