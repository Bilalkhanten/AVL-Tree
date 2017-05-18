#include<iostream>
using namespace std;
struct Node 
{
	int data;
	int height;
	Node *left;
	Node *right;
};
int max(int a, int b)
{
	if(a>b)
		return a;
	else 
		return b;	
}
int height(Node *temp)
{
	if(temp==NULL)
		return 0;
	return temp->height;	
}
int getbalance(Node *temp)
{
	if(temp==NULL)
		return 0;
	return height(temp->left)-height(temp->right);	
}
Node *leftrot(Node *x)
{
	Node *y=x->right;
	Node *z=y->left;
	
	y->left=x;
	x->right=z;
	
	x->height= max(height(x->left),height(x->right))+1;
	y->height= max(height(y->left),height(y->right))+1;
	
	return y;
}
Node *rightrot(Node *y)
{
	Node *x=y->left;
	Node *z=x->right;
	
	x->right=y;
	y->left=z;
	
	x->height= max(height(x->left),height(x->right))+1;
	y->height= max(height(y->left),height(y->right))+1;
	
	return x;
}
Node *insert(Node* node, int key)
{
    Node *temp=new Node;
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;
	temp->height=1;
	if(node==NULL)
		node=temp;
 
    if(node->data>key)
		node->left=insert(node->left,key);
	else if(node->data<key)
		node->right=insert(node->right,key);
	else 
		return node;
 
    /* 2. Update height of this ancestor node */
    node->height = max( height(node->left),height(node->right) ) +1;
 
    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getbalance(node);
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if(balance>1 && node->left->data>key)
		return rightrot(node);
	if(balance<-1 && node->right->data<key)
		return leftrot(node);
	if(balance>1 && node->left->data<key)
	{
		node->left= leftrot(node->left);
		return rightrot(node);
	}
	if(balance<-1 && node->right->data>key)
	{
		node->right=rightrot(node->right);
		return leftrot(node);
	}	
    /* return the (unchanged) node pointer */
    return node;
}
void preorder(Node* temp)
{
	if(temp==NULL)
		return ;
		
	cout<<temp->data<<"    ";
	preorder(temp->left);
	preorder(temp->right);
}
int main()
{
	Node *root=NULL;
	root=insert(root,10);
	root=insert(root,30);
	root=insert(root,60);
	root=insert(root,70);
	root=insert(root,110);
	root=insert(root,4);
	root=insert(root,7);
	root=insert(root,70);
	root=insert(root,5);
	root=insert(root,8);
	cout<<"AVL Tree in Pre-Order: "<<endl;
	preorder(root);
	return 1;
}	
