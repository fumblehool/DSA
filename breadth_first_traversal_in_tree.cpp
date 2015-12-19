//Program to traverse a binary tree.
#include <iostream>
#include <queue>
using namespace std;
//Structure of binary tree.
struct b_node{
    char data;
    b_node*left;
    b_node*right;
};
//pointer to address of root node.
b_node* root = NULL;
//Function to view tree in breadth first order.
void breadth_first_traversal();
//Function to view the whole tree.
void show_tree();
//Function to create the tree as returned by show_tree() function.
void create_tree();

//Main function
int main()
{
    show_tree(); //show_tree() function is called.
    create_tree(); //create_tree() function is called
    breadth_first_traversal(); //breadth_first_traversal() is called
    return 0;
}

void show_tree()
{
    cout<<"Tree is:"<<endl
    <<"          A \n"
    <<"         / \\ \n"
    <<"        B   C \n"
    <<"       /   / \\ \n"
    <<"      D   E   F \n"
    <<"         /      \n"
    <<"        G       \n";
}

void create_tree()
{
    b_node* a = new b_node(); // we create new nodes
    b_node* b = new b_node();
    b_node* c = new b_node();
    b_node* d = new b_node();
    b_node* e = new b_node();
    b_node* f = new b_node();
    b_node* g = new b_node();
    root = a;
    a->data = 'A';      //added data to the nodes
    b->data = 'B';
    c->data = 'C';
    d->data = 'D';
    e->data = 'E';
    f->data = 'F';
    g->data = 'G';
    a->left = b;    //fixed the links of the nodes
    a->right = c;
    b->left = d;
    b->right = NULL;
    c->left = e;
    c->right = f;
    e->left = g;
    d->left=d->right=g->left=g->right=e->right=f->left=f->right= NULL;

}

void breadth_first_traversal()
{
    queue <b_node*> q;  //we use queue to hold the addresses of nodes.
    q.push(root);

    cout<<"Breadth first order traversal of this tree is: ";
    while(!q.empty())
    {
        cout<<q.front()->data<<" ";
        if(q.front()->left!=NULL)
        {
            q.push(q.front()->left);
        }
        if(q.front()->right!=NULL)
        {
            q.push(q.front()->right);
        }
        q.pop();
    }
    cout<<endl;
}
