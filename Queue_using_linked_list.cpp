/* Demonstrate use of Queue data structure using linked list */
#include <iostream>
using namespace std;

struct node {  //structure of Node is defined here
    int data;
    node *next;
};

node * start = NULL; //we take a start pointer to store address of front node.
node * rear = NULL;  //we take rear pointer to store address of rear node.

void view();    //function to display queue
void enqueue(int n); //function to enqueue the element
void dequeue();     //function to dequeue the element
bool isEmpty();     //function to check if queue is empty

int main()    //main program
{
    int x,y;
    while(true)
    {
        cout<<"Enter code for following operations:\n 1 to enqueue \n 2 to dequeue \n 3 to view queue \n 4 to quit\n";
        cin>>x;
        switch(x)
        {
            case 1: cout<<"Enter value to enqueue: ";
                    cin>>y;
                    enqueue(y);
                    break;
            case 2: dequeue();
                    break;
            case 3: view();
                    break;
            case 4: cout<<"Goodbye";
                    return 0;
            default: cout<<"Enter code properly\n";
                    break;
        }
    }

}
// All function definitions
void view()
{
    node *ptr;

    if(isEmpty())
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    else{
        cout<<"Queue is: ";
        ptr = start;
        while(ptr != NULL)
        {
            cout<<ptr->data<<" ";
            ptr= ptr->next;
        }
    }
    cout<<endl<<endl;
}

void enqueue(int n)
{
    node *temp = new node;
    temp->data = n;
    temp->next = NULL;

    if(isEmpty())
    {
        start = temp;
        rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
}


void dequeue()
{
    if(isEmpty())
    {
        cout<<"Underflow"<<endl;
        return;
    }
    else{
        node *temp = start;
        start = start->next;
        delete temp;
    }
}

bool isEmpty()
{
    if(start ==NULL)
    {
        return true;
    }
    return false;

}
