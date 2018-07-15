#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};

struct node *root = NULL;

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

struct node *inorder(struct node *ptr)
{
	if(ptr != NULL)
	{
		inorder(ptr -> left);
		cout<<ptr -> data<<" ";
		inorder(ptr -> right);
	}
}

bool search(int val)
{
	struct node *ptr = root;
	while(ptr != NULL)
	{
		if(ptr -> data == val)
			return true;
		else if(val < ptr -> data)
			ptr = ptr -> left;
		else
			ptr = ptr -> right;
	}
	return false;
}

int main (void)
{
	int n,val,ser;
	cin>>n;
	while(n--)
	{
		cin>>val;
		createBST(val);
	}
	inorder(root);
	cin>>ser;
	while(ser--)
	{
		cin>>val;
		cout<<search(val)<<endl;
	}
}