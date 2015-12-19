//Program to traverse a binary tree.
#include <iostream>
using namespace std;
//Structure of binary tree.
struct b_node{
    char data;
    b_node*left;
    b_node*right;
};
//pointer to address of root node.
b_node* root = NULL;
//Function to view tree in prefix order.
void show_prefix(b_node* root);
//Function to view tree in postfix order.
void show_postfix(b_node* root);
//Function to view tree in infix order.
void show_infix(b_node* root);
//Function to view the whole tree.
void show_tree();
//Function to create the tree as returned by show_tree() function.
void create_tree();

//Main function
int main()
{
    show_tree();
    create_tree();
    cout<<"Prefix order of given tree is: \n";
    show_prefix(root);
    cout<<endl;
    cout<<"infix order of given tree is: \n";
    show_infix(root);
    cout<<endl;
    cout<<"Postfix order of given tree is: \n";
    show_postfix(root);
    cout<<endl;
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

void show_prefix(b_node* root)
{
    if(root == NULL)
        return ;

    cout<<root->data<<" ";
    show_prefix(root->left);
    show_prefix(root->right);
}
void show_postfix(b_node* root)
{
    if(root == NULL)
        return ;

    show_postfix(root->left);
    show_postfix(root->right);
    cout<<root->data<<" ";
}
void show_infix(b_node* root)
{
    if(root == NULL)
        return ;

    show_infix(root->left);
    cout<<root->data<<" ";
    show_infix(root->right);
}
