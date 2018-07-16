#include <bits/stdc++.h>
using namespace std;

struct node 
{
	int data;
	struct node *left, *right;
};

struct node *root = NULL;

void inorder(struct node *ptr)
{
	if(ptr != NULL)
	{
		inorder(ptr -> left);
		cout<<ptr -> data<<" ";
		inorder(ptr -> right);
	}
}

struct node *createBST(int val)
{
	struct node *newnode = new node;
	newnode -> data = val;
	newnode -> left = NULL;
	newnode -> right = NULL;
	if(root == NULL)
		root = newnode;
	else
	{
		struct node *ptr = root, *preptr = root;
		while(ptr != NULL)
		{
			preptr = ptr;
			if(val < ptr -> data)
				ptr = ptr -> left;
			else
				ptr = ptr -> right;
		}
		if(val < preptr -> data)
			preptr -> left = newnode;
		else
			preptr -> right = newnode;
	}
}

void delete(int val)
{
	
}

int main (void)
{
	int n,val,del;
	cin>>n;
	while(n--)
	{
		cin>>val;
		createBST(val);
	}
	inorder(root);
	while(del--)
	{
		cin>>val;
		delete(val);
	}

}