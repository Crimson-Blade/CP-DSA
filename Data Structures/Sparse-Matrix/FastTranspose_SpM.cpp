#include <iostream>
using namespace std;
#define Max 10
class spm
{
    int r,c,v;
public:
    void read(spm a[],int m,int n);
    void fast_transpose(spm a[],spm b[]);
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
void spm::fast_transpose(spm a[],spm b[])
{
    int k=1,i,rT[Max],sp[Max];
    b[0].r=a[0].c;
    b[0].c=a[0].r;
    b[0].v=a[0].v;
    //initializing to 0
    for(i=0;i<a[0].c;i++)
        rT[i]=0;
    //counting the number of non-zero elements in each column
    for(i=1;i<a[0].v;i++)
        rT[a[i].c]++;
    sp[0]=1;
    //finding the starting position of each column
    for(i=1;i<a[0].c;i++)
        sp[i]=sp[i-1]+rT[i-1];
    
    for(i=1;i<=a[0].v;i++)
    {
        k=sp[a[i].c]++;
        b[k].r=a[i].c;
        b[k].c=a[i].r;
        b[k].v=a[i].v;
    }
    cout<<"After Transposing\n";
    for(int i=0;i<=b[0].v;i++)
        cout<<b[i].r<<' '<<b[i].c<<' '<<b[i].v<<endl;
}
int main()
{
    int m,n;
    cout<<"Enter Dimensions of the Matrix\n";
    cin>>m>>n;
    spm a[Max],b[Max],a1;
    a1.read(a,m,n);
    a1.fast_transpose(a,b);
}
