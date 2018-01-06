// Search and Insertion in BST;
/*
     100
    /   \
   20   500 
  /  \  
 10   30
       \   
        40
*/


#include <iostream>
using namespace std;

//binary search tree node
struct b_node{
	int info;
	b_node* left;
	b_node* right;
};

//root, par and loc pointer to nodes.
b_node* root = NULL;
b_node* loc = NULL;
b_node* par = NULL;

//function to insert node in bst.
void b_node_insert(int data);

//function which creates a new node
//and returns the address of new node.
b_node* create_node(int data);

//function to search bst.
void b_search(int data);

//main function
int main(){
	//values to be added to initial bst.
    int data[6] = {100, 500, 30, 40, 20, 10};
	for(int i=0;i<6;i++){
		b_node_insert(data[i]);
	}

	while(true){
		int a;
		cout<<"enter 1 to search, 2 to insert, -1 to quit"<<endl;
		cin>>a;
		if(a == -1) break;
		if(a == 1){
			cout<<"enter element to search: 100, 500, 30, 40, 20, 10"<<endl;
			cin>>a;
			if(a == -1) break;
			par = loc = NULL;
			b_search(a);
			if(loc == NULL){
		    	cout<<"element does not exist"<<endl;
		  	}
		  	else{
		    	cout<<"element exists!!"<<endl;
		  	}
		}
		else{
			int b;
			cout<<"enter element";
			cin>>b;
			b_node_insert(b);
		}
	}
    return 0;
}

void b_node_insert(int data){
	//create ptr pointer.
	b_node* ptr = root;

	//check for empty tree.
	if(ptr == NULL){
    	root = create_node(data);
        return;
    }
	
	//Search for node in bst.
	par = loc = NULL;
	b_search(data);
	if(loc != NULL){
		cout<<"node already exists!!!!"<<endl;
		return;
	}
	
	//if node does not exist, create one.
	b_node* new_node = create_node(data);

	if(par == NULL){
		root = new_node;
	}
	else if(data < par->info){
		par->left = new_node;
	}
	else{
		par->right = new_node;
	}
}

b_node* create_node(int data){
	b_node* node = new b_node();
	node->info = data;
	node->left = node->right = NULL;
	return node;
}

void b_search(int data){
	b_node* ptr = root;
	if (ptr == NULL) return;

	//node present at root;
	if(ptr->info == data){
		loc = ptr;
		return;
	}
	
	//assign par to root and set 
	//ptr to subtree of root.
	par = ptr;
	if(data < ptr->info){
		ptr = ptr->left;
	}
	else{
		ptr = ptr->right;
	}

	//traverse tree until ptr == NULL;
	while(ptr != NULL){
		//node found, set loc to ptr.
		if(data == ptr->info){
			loc = ptr;
			return;
		}
		//data < ptr->info, goto left subtree.
		if(data < ptr->info){
			par = ptr;
			ptr = ptr->left;
		}
		//data > ptr->info, goto right subtree.
		else{
			par = ptr;
			ptr = ptr->right;
		}
	}
}
