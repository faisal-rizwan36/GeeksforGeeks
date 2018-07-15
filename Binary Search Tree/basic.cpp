#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left = NULL, *right = NULL;
};

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
		struct node *ptr = root;
		struct node *preptr = root;
		while(ptr != NULL)
		{
			preptr = ptr;
			if(ptr -> data > val)
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

int main (void)
{
	int n,val;
	cin>>n;
	while(n--)
	{
		cin>>val;
		createBST(val);
	}
	inorder(root);
}