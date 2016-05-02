#include <iostream>
using namespace std;

void merge_sort(int a[],int low, int high);
void merge_arrays(int a[],int low,int high,int mid);
void print(int a[],int n); //utility to print an array.
int main()
{
    int a[20],i,n;
    cout<<"Enter size of array: ";
    cin>>n;

    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Before sorting"<<endl;
    print(a,n);
    cout<<"\nAfter sorting"<<endl;
    merge_sort(a,0,n);
    print(a,n);

    return 0;
}

void print(int a[],int n)
{
    int i;
    cout<<"Array is:"<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<endl;
}

void merge_sort(int a[],int low, int high)
{
    if (low < high)
    {
        int mid = low + (high-low)/2;

        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge_arrays(a,low,high,mid);
    }
}

void merge_arrays(int a[],int low,int high,int mid)
{
    int n_left = mid-low+1;
    int n_right = high-mid;
    int n_left_array[n_left], n_right_array[n_right];

    for(int i=0;i<n_left;i++)
        n_left_array[i] = a[low+i];
    for(int j=0;j<n_right;j++)
        n_right_array[j] = a[mid+1+j];

    int i=0,j=0,k=low;

    while (i<n_left && j<n_right)
    {
        if(n_left_array[i]<=n_right_array[j])
        {
            a[k] = n_left_array[i];
            i++;
        }
        else{
            a[k] = n_right_array[j];
            j++;
        }
        k++;
    }

    while( i<n_left )
    {
        a[k] = n_left_array[i];
        i++;
        k++;
    }

    while( j<n_right )
    {
        a[k] = n_right_array[j];
        j++;
        k++;
    }

}
