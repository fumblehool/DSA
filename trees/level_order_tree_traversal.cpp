//level order tree traversal
//O(n^2)
#include <iostream>
using namespace std;

//tree node structure
struct node {
  int info;
  node* left, right;
};

//function to create new node
node* newNode(int data);

//function to print level order
void printLevelOrder(node* root);

//function to get height of tree
int tree_height(node* root);

//function to print given level elements
void printGivenLevel(node* root, int height);

/* Driver program to test above functions*/
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    cout<<"Level Order traversal of binary tree is "<<endl;
    printLevelOrder(root);

    return 0;
}

void printLevelOrder(node* root){
    int height = tree_height(root);
    for(int i=1;i<=height;i++){
        printGivenLevel(root, i);
    }
}

node* newNode(int data){
    node* new_node = new node();
    new_node->info = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int tree_height(node* root){
    if(root == NULL){
        return 0;
    }
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);

    if(left_height > right_height){
        return (left_height+1);
    }
    else{
        return (right_height+1);
    }
}

void printGivenLevel(node* root, int height){
    if(root == NULL){
        return;
    }
    if(height == 1){
        cout<<root->info<<" ";
        return;
    }
    else if(height > 1){
        printGivenLevel(root->left, height-1);
        printGivenLevel(root->right, height-1);
    }
}
