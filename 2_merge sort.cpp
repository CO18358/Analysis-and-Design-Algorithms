#include<iostream>
#include<cstdlib>
using namespace std;

int count = 0;c

void merge(int array[], int p, int q, int r);
void merge_sort(int array[], int p, int r);

int main()
{
	int size,p, r, c,a,num=1;
	//car ch = 'y';
	cout<<"___MERGE SORT___"<<endl;
	//do{
	cout<<"Enter size of array: ";
	cin>>size;
	cout<<"Enter elements of array: ";
	//user
	/*for(c=0;c<size;c++)
	{
		cin>>array[c];
	}*/
	//auto
	int array[size];
	for(a=0;a<size;a++)
	{
		array[a] = rand()%10000;
	} 
	p = 0, r = size-1;
	merge_sort(array, p, r);

	cout<<"\nSorted array: \n";
	for(c=0;c<size;c++)
	{
		cout<<array[c]<<" ";
	}
	cout<<"\n\n";
	cout<<"Number of comparisons done: "<<count<<endl;
	/*count=0;
	cout<<"\n\n do you wish to continue: ";
    cin>>ch;
	}while(ch=='y'||ch=='Y');*/
	return 0;
}

void merge(int array[], int p, int q, int r)
{
	int m, n, i, j, k;
	m = q-p+1;
	n = r-q;
	int left[m], right[n];
	left[m] = 2147483647;
	right[n] = 2147483647;
	for(i=0;i<m;i++)
		left[i] = array[p+i];
	for(j=0;j<n;j++)
		right[j] = array[q+j+1];
	
	i=j=0;
	for(k=p;k<=r;k++)
	{
		if(left[i]<=right[j])
		{
			array[k] = left[i];
			i++;
			count++;
		}
		else
		{
			array[k] = right[j];
			j++;
			count++;
		}
	}
	cout<<"\n\n Sub Array: ";
	for(m = p; m<=r;m++)
	{
		cout<<array[m]<<" ";
	}
	cout<<"\n";
}

void merge_sort(int array[], int p, int r)
{
	if(p<r)
	{
		int q;
		q = (p+r)/2;
		merge_sort(array, p ,q);
		merge_sort(array, q+1 ,r);
		merge (array, p, q, r);
	}
}


