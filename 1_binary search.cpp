#include <iostream> 
using namespace std;


int binarySearch(int arr[], int first, int last, int find) 
{ 
	static int count =0 ;
    if (last >= first) { 
        int mid = (first+last)/ 2; 
        count++;
        if (arr[mid] == find) 
        	{
				cout<<"Number of comparisons done: "<<count<<endl;
            	return mid; 
		}
        else if (arr[mid] > find) 
            return binarySearch(arr, first, mid - 1, find); 
        else
			return binarySearch(arr, mid + 1, last, find); 
    } 
    return -1; 
} 
  
int main() 
{ 
	int array[1000], i, n, find,num=1;
	//char ch = 'y';
	cout<<"___BINARY SEARCH___"<<endl;
//	do{
	cout<<"Enter size of array: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		array[i] = num;
		num++;
	} 
	cout<<"Numbers 1 to "<<n<<" are inserted in array. \n";
	cout<<"Enter the element to search: ";
	cin>>find;
    int result = binarySearch(array, 0, n - 1, find); 
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result<<endl; 
/*    cout<<"\n\n do you wish to continue: ";
    cin>>ch;
	}while(ch=='y'||ch=='Y');*/
    return 0; 
} 
