#include <iostream>
using namespace std;

void insertion_sort(int a[],int n);
void print(int a[],int n); //utility to print an array.
int main()
{
    int a[20],i,n;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter array elements:"<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Before sorting"<<endl;
    print(a,n);
    cout<<"\nAfter sorting"<<endl;
    insertion_sort(a,n);
    print(a,n);

    return 0;
}

void insertion_sort(int a[],int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key = a[i];
        j= i-1;

        while(j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = key;

    }


}
void print(int a[],int n)
{
    int i;
    cout<<"Array is:"<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<endl;
}
