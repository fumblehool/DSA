#include <iostream>
using namespace std;

bool isfull();

void enqueue(int item);

void dequeue();

bool isempty();

void print();

int Q[20];
int start=-1,finish=-1;
int main()
{
    int t,x,y;
    cout<<"Enter test cases: ";
    cin>>t;
    while(t--)
        {
            cout<<"Enter operation:"<<" 1 for enqueue ";
            cout<<"2 for dequeue"<<endl;
            cin>>x;
            cout<<endl;

            if(x==1)
            {
                cout<<"Enter value of element.";
                cin>>y;
                enqueue(y);
                print();
            }
            else if(x==2){
                dequeue();
                print();
            }
            else{
                cout<<"Wrong input. Try Again"<<endl;
                t++;
            }
        }

    return 0;
}

void print()
{
    cout<<endl<<"Queue is "<<endl;
    for(int i=start+1;i<=finish;i++)
    {
        cout<<Q[i]<<endl;
    }
    cout<<endl;
}

bool isempty()
{
    if(start==-1 && finish==-1)
    {
        return true;
    }
    return false;

}

bool isfull()
{
    if(start==0 && finish==19)
    {
        return true;
    }
    return false;

}

void enqueue(int item)
{
    if(isfull())
    {
        cout<<"Overflow"<<endl;
        return ;
    }
    else {
        cout<<"using Enqueue using the integer "<<item<<endl;
        finish = (finish+1)%20;
        Q[finish] = item;
        return ;
    }

}

void dequeue()
{
    if(isempty())
    {
        cout<<"Underflow"<<endl;
        return ;
    }
    else{
        cout<<"using dequeue operation on the queue"<<endl;
        start+=1;
    }
}