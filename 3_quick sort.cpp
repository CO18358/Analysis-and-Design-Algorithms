#include<iostream>
#include<cstdlib>
using namespace std;

int count = 0,i, j,x, up, down, pi,temp;

int partition(int array[], int up, int down)
{
	pi = array[up];
	i = up;
	j = down;
	while(1)
	{
		while(array[j]>pi)
		{
			j--;
		}
		while(array[i]<pi)
		{
			i++;
		}
		if(i<j)
		{
			swap(array[i],array[j]);
			count++;
		}
		else
		{
			swap(pi,array[j]);
			count++;
			return(j);
		}
	}	
}

void quick_sort(int array[], int up, int down)
{
	if(up<down)
	{
		pi = partition(array, up, down);
		quick_sort(array,up,pi-1);
		quick_sort(array,pi+1,down);
	}
}

void swap(int a, int b) 
{ 
    temp = a;
    a = b;
    b = temp;
}

int main()
{
	int array[10000], size,p, r, c;
	cout<<"___QUICK SORT___"<<endl;
	cout<<"Enter size of array: ";
	cin>>size;
	//cout<<"Enter elements of array: ";
	for(c=0;c<size;c++)
	{
		array[c]=rand()%1000000;
	}
	up = 0, down = size-1;
	quick_sort(array, up, down);

	cout<<"Sorted array: \n";
	for(c=0;c<size;c++)
	{
		cout<<array[c]<<" ";
	}cout<<endl<<endl;
	cout<<"Number of comparisons done: "<<count<<endl;
	
	return 0;
}


