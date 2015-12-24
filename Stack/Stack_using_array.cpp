#include <iostream>
using namespace std;

int stack[20];
int top=-1;

void push(int item);
void pop();
int top_();
bool isEmpty();
bool isFull();
void print();
int main()
{
    int x,y;
    
    while(true)
    {
        cout<<"Enter operation:"<<" 1 to push. ";
        cout<<"2 to pop. "<<"3 to top. "<<"4 to print the stack. "<<"5 to exit."<<endl;
        cin>>x;
        switch(x){
            case 1 :    cout<<"Enter Value to be pushed";
                        cin>>y;
                        push(y);
                        break;
            case 2 :    pop();
                        break;
            case 3 :    if(top_()==-1)
                        {
                            cout<<"Stack is Empty"<<endl;
                        }
                        else{
                            cout<<"value of element at top is "<<top_()<<endl;
                        }
                        break;
            case 4 :    print();
                        break;
            case 5 :    return 0;          
            default:    cout<<"Wrong Value"<<endl<<"Try Again"<<endl;
                }
    }
    return 0;
}

bool isEmpty()
{
    if(top==-1)
    {
        return true;
    }
    return false;
}

bool isFull()
{
    if(top==19)
    {
        return true;
    }
    return false;
}

void push(int item)
{
    if(isFull())
    {
        cout<<"Overflow"<<endl;
        return ;
    }
    top++;
    stack[top]=item;
}
void pop()
{
    if(isEmpty())
    {
        cout<<"Underflow"<<endl;
        return ;
    }
    top--;
}
int top_()
{
    if(isEmpty())
    {
        return -1;
    }
    else {
        return stack[top];
    }
}
    
void print()
{
    cout<<"Stack is ";
    for(int i=0;i<=top;i++)
    {
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}
