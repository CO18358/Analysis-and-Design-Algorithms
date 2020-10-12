//Vasu Garg - CO18358

#include <iostream>
#include <cstdlib>
#include<climits>
#define INF 99999

using namespace std;

long int m[20][20];
int s[20][20];
int p[20],i,j,n;

void matrixmul()
{
long int q;
int k;
for(i=n;i>0;i--)
 {
   for(j=i;j<=n;j++)
    {
     if(i==j)
       m[i][j]=0;
     else
       {
        for(k=i;k<j;k++)
        {
         q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
         if(q<m[i][j])
          {
            m[i][j]=q;
            s[i][j]=k;
          }
         }
        }
      }
 }
}

int MatrixChainOrder(int p[], int i, int j)
{
    if(i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;
 
    for (k = i; k <j; k++)
    {	
    	cout<<"## Subproblems of Size – "<<i<<endl;
    	cout<<"Number of Subproblems of Size "<<i<<" is: "<<j-i;
        count = MatrixChainOrder(p, i, k) +
                MatrixChainOrder(p, k+1, j) +
                p[i-1]*p[k]*p[j];
 
        if (count < min)
            min = count;
    }
 
    return min;
}

int main()
{
int k;
cout<<"Enter the no. of matrices: ";
cin>>n;
for(i=1;i<=n;i++)
for(j=i+1;j<=n;j++)
{
 m[i][i]=0;
 m[i][j]=INF;
 s[i][j]=0;
}
cout<<"\nEnter the dimensions of matrix chain: "<<endl;
for(k=0;k<=n;k++)
{
 cout<<"P"<<k<<": ";
 cin>>p[k];
}
matrixmul();
cout<<endl<<"Cost Matrix M:"<<endl;
for(i=1;i<=n;i++)
{
	for(j=i;j<=n;j++)
	{
		cout<<m[i][j]<<"\t";
	}
  	cout<<endl;
}
 

i=1,j=n;
cout<<endl<<"Solution Matrix S:"<<endl;
for(i=1;i<=n;i++)
{
	for(j=i;j<=n;j++)
	{
		cout<<s[i][j]<<"\t";
	}
  	cout<<endl;
}
return 0;
}
