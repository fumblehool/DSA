#include <iostream>
using namespace std;

struct node {
  int info;
  node* left;
  node* right;
};

node* newNode(int data);

int diameter(node* root);

int tree_height(node* root);

/* Driver program to test above functions*/
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    cout<<"Diameter or Width of binary tree is "<<endl;
    cout<<diameter(root);

    return 0;
}

//O(n^2)
//diameter is max of - 
//1. height of left subtree + height of right sub-tree+1 (add root)
//2. diameter taking root as node in left or right sub tree.
int diameter(node* root){
    if(root == NULL){
        return 0;
    }

    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);

    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);

    int result = max(left_height + right_height + 1, max(left_diameter, right_diameter));
    return result;
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

//Optimised Solution O(n)
/*
//*The second parameter is to store the height of tree.
//   Initially, we need to pass a pointer to a location with value
//   as 0. So, function should be used as follows:
//
//   int height = 0;
//   struct node *root = SomeFunctionToMakeTree();
//   int diameter = diameterOpt(root, &height);
int diameterOpt(struct node *root, int* height)
{
  //* lh --> Height of left subtree
  //   rh --> Height of right subtree
  int lh = 0, rh = 0;

  //* ldiameter  --> diameter of left subtree
  //   rdiameter  --> Diameter of right subtree
  int ldiameter = 0, rdiameter = 0;

  if(root == NULL)
  {
    *height = 0;
     return 0; // diameter is also 0
  }

  // Get the heights of left and right subtrees in lh and rh
  //  And store the returned values in ldiameter and ldiameter
  ldiameter = diameterOpt(root->left, &lh);
  rdiameter = diameterOpt(root->right, &rh);

  // Height of current node is max of heights of left and
  //   right subtrees plus 1
  *height = max(lh, rh) + 1;

  return max(lh + rh + 1, max(ldiameter, rdiameter));
}
*/
