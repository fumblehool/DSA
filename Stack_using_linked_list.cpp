#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *top = NULL;
node * base = NULL;
void push(int n);
void pop();
void view();
bool isEmpty();

int main()
{
    int x,y;
    while(true)
    {
        cout<<"Enter code for following operations:\n 1 to push \n 2 to pop \n 3 to view stack \n 4 to quit\n";
        cin>>x;
        switch(x)
        {
            case 1: cout<<"Enter value to enqueue: ";
                    cin>>y;
                    push(y);
                    break;
            case 2: pop();
                    break;
            case 3: view();
                    break;
            case 4: cout<<"Goodbye";
                    return 0;
            default: cout<<"Enter code properly\n";
                    break;
        }
    }



    return 0;
}

void push(int n)
{
    node *temp = new node;
    temp->data = n;
    temp->next = NULL;
    if(isEmpty())
    {
        base = temp;
        top = temp;
    }
    else{
        top->next = temp;
        top = temp;
    }
}
void pop()
{
    if(isEmpty())
    {
        cout<<"Underflow"<<endl;
        return;
    }
    else if(base == top){
        node *temp = top;
        base = NULL;
        top = NULL;
        delete temp;
    }
    else{
        node *ptr = base;
        node *temp = NULL;
        node *del = top;
        while(ptr !=top)
        {
            temp = ptr;
            ptr= ptr->next;
        }
        top = temp;
        top->next = NULL;
        delete del;
    }


}
void view()
{
    if(isEmpty())
    {
        cout<<"Stack is empty"<<endl;
        return;
    }
    else{
        cout<<"Stack is: ";
        node *ptr = base;
        while(ptr !=NULL)
        {
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
    }
    cout<<endl<<endl;

}


bool isEmpty()
{
    if(top == NULL)
    {
        return true;
    }
    return false;
}
