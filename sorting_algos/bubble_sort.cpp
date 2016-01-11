#include <iostream>
using namespace std;

void swap_int(int *x, int *y);
void bubble_sort(int a[],int n);
void print(int a[],int n); //utility to print an array.
int main()
{
    int a[20],i,n;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter elements: \n";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Before sorting"<<endl;
    print(a,n);
    cout<<"\nAfter sorting"<<endl;
    bubble_sort(a,n);//bubble_sort function is called
    print(a,n);

    return 0;
}

void swap_int(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int a[],int n)
{
    int i,j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j < n-i-1 ;j++)
        {
            if(a[j] > a[j+1])
				swap_int(&a[j], &a[j+1]);
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
