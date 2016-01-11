#include <iostream>
using namespace std;

void swap_int(int *x, int *y);
void selective_sort(int a[],int n);
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
    selective_sort(a,n);
    print(a,n);

    return 0;
}


void swap_int(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selective_sort(int a[],int n)
{
    int i,j,min_index;
    for(i=0;i<n-1;i++)
    {
        min_index = i;
        for(j=i+1;j<n;j++)
        {
            if(a[min_index] > a[j])
                min_index = j;

            swap_int(&a[i], &a[min_index]);
        }


    }


}
void print(int a[],int n)
{
    int i;
    cout<<"Array is:"<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<endl;
}
