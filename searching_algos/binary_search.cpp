#include <iostream>
using namespace std;

int binary_search(int array[], int n, int q);

int main()
{

    int a[5] = {2,4,8,9,15}, query = 4, num = 5;
    if (binary_search(a,num,query) == 1 ){
        cout<<"4 is present in the array"<<endl;
    }
    else{
        cout<<"4 is not present in the array"<<endl;
    }

}


int binary_search(int array[], int n, int q)
{
    int low=0, high=n-1;

    while( low<= high )
    {
	int mid = low + (high-low)/2;
	if (array[mid] == q )
	{
	    return 1;
	}

	else if ( array[mid] >q)
	{
	    high = mid-1;
	}

	else {
	    low = mid+1;
	   }
    }

    return -1;
}
