// Program to perform insertion operations on a linear linked list.
#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

void traverse();
void insert_at_begin(int n);
void insert_at_end(int n);
void insert_after_given_node(int n,int loc);
node *head = NULL;

int main()
{
    int x,y,l;
    while(true)
    {
        cout<<"Enter one of following operations: "<<endl;
        cout<<"1 to insert element at beginning\n";
        cout<<"2 to insert element at end\n";
        cout<<"3 to insert after given node\n";
        cout<<"4 to view the list by traversing\n";
        cout<<"5 to exit\n";
        cin>>x;

        switch(x){
            case  1:    cout<<"Enter data value to be inserted: ";
                        cin>>y;
                        insert_at_begin(y);
                        break;
            case  2:    cout<<"Enter data value to be inserted: ";
                        cin>>y;
                        insert_at_end(y);
                        break;
            case  3:    cout<<"Enter the element to be inserted: ";
                        cin>>y;
                        cout<<"Ener the location where you want to insert this element: ";
                        cin>>l;
                        insert_after_given_node(y,l);
                        break;
            case  4:    traverse();
                        break;
            case  5:    cout<<"Goodbye"<<endl;
                        return 0;
            default :   cout<<"Please enter valid operation code.\n";
                        break;
        }
        cout<<endl;

    }


    return 0;
}

void traverse()
{
    node *ptr = head;
    if(ptr == NULL)
    {
        cout<<"list is empty\n";
        return;
    }
    cout<<"List is :\n";
    while(ptr->next !=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
        cout<<ptr->data;
}


void insert_at_begin(int n)
{
    node *ptr = head;

    node *temp = new node();
    temp->data = n;
    temp->next = NULL;

    if( ptr == NULL)
    {
        head = temp;
    }
    else{
        temp->next = ptr;
        head = temp;
    }

}

void insert_at_end(int n)
{
    node *temp = new node();
    temp->data = n;
    temp->next = NULL;

    node *ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;

}

void insert_after_given_node(int n,int loc)
{
    node *temp = new node();
    temp->data = n;
    temp->next = NULL;

    int c = 0;
    node *ptr = head;
    while(ptr->next !=NULL)
    {
        c++;
        if(c == loc)
        {
            node *temp2 = ptr->next;
            ptr->next = temp;
            temp->next = temp2;
        }
        ptr = ptr->next;
    }

}
