#include <iostream>
using namespace std;
#define Max 10
class spm
{
    int r,c,v;
public:
    void read(spm a[],int m,int n);
    void transpose(spm a[],spm b[],int m,int n);
};
void spm::read(spm a[],int m,int n)
{
    int k=1,ele;
    a[0].r=m;
    a[0].c=n;
    cout<<"Enter the elements\n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>ele;
            if(ele==0)
                continue;
            a[k].r=i;
            a[k].c=j;
            a[k].v=ele;
            k++;
        }
    }
    a[0].v=k-1;
    cout<<"Before Transposing\n";
    for(int i=0;i<=a[0].v;i++)
        cout<<a[i].r<<' '<<a[i].c<<' '<<a[i].v<<endl;
}
void spm::transpose(spm a[],spm b[],int m,int n)
{
    int k=1;
    b[0].r=a[0].c;
    b[0].c=a[0].r;
    b[0].v=a[0].v;
    for(int i=0;i<a[0].c;i++)
    {
        for(int j=1;j<=a[0].v;j++)
        {
            if(i==a[j].c)
            {
                b[k].c=a[j].r;
                b[k].r=a[j].c;
                b[k].v=a[j].v;
                k++;
            }
        }
    }
    cout<<"After Transposing\n";
    for(int i=0;i<=b[0].v;i++)
        cout<<b[i].r<<' '<<b[i].c<<' '<<b[i].v<<endl;
}
int main()
{
    int m,n,k=0;
    cout<<"Enter Dimensions of the Matrix\n";
    cin>>m>>n;
    spm a[Max],b[Max],a1;
    a1.read(a,m,n);
    a1.transpose(a,b,m,n);
}
