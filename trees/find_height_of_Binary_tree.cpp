//Program to find the height of a binary tree.
#include <iostream>
using namespace std;
//Structure of binary tree.
struct b_node{
    char data;
    b_node*left;
    b_node*right;
};
//pointer to root node.
b_node* root = NULL;

//Recursive function to find height of tree.
int findHeight(b_node *root);
//Function to view the tree.
void show_tree();
//Function to create the tree as shown by show_tree() function.
void create_tree();
//main function
int main()
{
    show_tree();
    create_tree();
    cout<<"Height of tree is : "<<findHeight(root)<<endl;
    return 0;
}

void show_tree()
{
    cout<<"Tree is:"<<endl
    <<"          A \n"
    <<"         / \\ \n"
    <<"        B   C \n"
    <<"       /   / \\ \n"
    <<"      D   E   F \n";
}

void create_tree()
{
    b_node* a = new b_node();
    b_node* b = new b_node();
    b_node* c = new b_node();
    b_node* d = new b_node();
    b_node* e = new b_node();
    b_node* f = new b_node();
    root = a;
    a->data = 'A';
    b->data = 'B';
    c->data = 'C';
    d->data = 'D';
    e->data = 'E';
    f->data = 'F';
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = NULL;
    c->left = e;
    c->right = f;
    d->left=d->right=e->left=e->right=f->left=f->right= NULL;
}

int findHeight(b_node *root)
{
    if(root == NULL)
    {
        return -1;
    }
    return(max(findHeight(root->left),findHeight(root->right))+1);
}
