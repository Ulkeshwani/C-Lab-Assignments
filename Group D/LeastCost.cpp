#include<iostream>
#define MAX 10
using namespace std;
int p[MAX],q[MAX],w[MAX][MAX],c[MAX][MAX],r[MAX][MAX];
char idnt[7][MAX];
int i=0,j=0,k=0,a=0,b=0,m=0;
int find(int , int );
void print(int ,int);
int find(int i,int j){
    int min=2000,m=0,l=0;
    for(m=i+1;m<=j;m++){
        if(c[i][m-1]+c[m][j]<min){
            min=c[i][m-1]+c[m][j];
            l=m;
        }
    }
    return l;
}
void print(int i,int j)
{
    if(i<j)
        cout<<idnt[r[i][j]];
    else
    return ;
    print(i,r[i][j]-1);
    print(r[i][j],j);
}
int main(){
    cout<<"\nEnter the No. OF identifiers";
    cin>>a;
    cout<<"\nEnter the Identifiers";
    for(i=0;i<=a;i++){
        cin>>idnt[i];
    }
    cout<<"\nEnter the Success Probability of Identifiers";
    for(i=0;i<=a;i++){
        cin>>p[i];
    }
    cout<<"\nEnter the Failure Probability of Identifiers";
    for(i=0;i<=a;i++){
        cin>>q[i];
    }
    for(i=0;i<=a;i++){
        w[i][i]=q[i];
        c[i][i]=r[i][i];
        w[i][i+1]=q[i]+q[i+1]+p[i+1];
        r[i][i+1]=q[i]+q[i+1]+p[i+1];
    }
    w[a][a]=q[a];
    r[a][a]=c[a][a]=0;
    for(m=0;m<=a;m++){
        for(i=0;i<=a-m;i++){
            j=i+m;
            w[i][j]=w[i][j-1]=p[j]+q[j];
            k=find(i,j);
            r[i][j]=k;
            c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
        }
    }
    cout<<"\n";
    print(0,a);
}