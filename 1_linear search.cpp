#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
	int array[10000], i, n, find, flag = 0, count = 1;
	cout<<"___LINEAR SEARCH___"<<endl;
	cout<<"Enter size of array: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		array[i] = rand()%1000;
	}
	
	cout<<"Element to search: ";
	find = rand()%10000;
	cout<<endl;
	for(i=0;i<n;i++)
	{
		if(array[i]==find)
		{
			cout<<"Element "<<find<<"is present at "<<i+1<<"th location in array."<<endl;
			flag = 1;
			break;
		}
		count++;
	}
	
	if(flag != 1)
		cout<<"Element "<<find<<"is not present in the array"<<endl;
	cout<<"Number of comparisons done: "<<count<<endl;
		
	return 0;
}
