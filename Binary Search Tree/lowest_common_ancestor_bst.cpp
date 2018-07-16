#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left = NULL, *right = NULL;
};

struct node *root = NULL;

struct node *createBST(int val)
{
	struct node *newnode = new node;
	newnode -> data = val;
	newnode -> left = NULL;
	newnode -> right = NULL;
	if(root == NULL)
		root  = newnode;
	else
	{
		struct node *ptr = root,*preptr = root;
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

void inorder(struct node *ptr)
{
	if(ptr != NULL)
	{
		inorder(ptr -> left);
		cout<<ptr->data<<" ";
		inorder(ptr->right);
	}
}

int lowestCommAnces(int a, int b)
{
	int x = min(a,b);
	int y = max(a,b);
	struct node *ptr = root;
	if(ptr == NULL)
		return -1;
	while(ptr != NULL)
	{
		if((x <= ptr -> data ) && (y >= ptr -> data))
			return ptr -> data;
		else if(x < ptr -> data && y < ptr -> data)
			ptr = ptr -> left;
		else
			ptr = ptr -> right;
	}
}

int main (void)
{
	int n,val,lca;
	cin>>n;
	while(n--)
	{
		cin>>val;
		createBST(val);
	}
	inorder(root);
	cout<<endl;
	cin>>lca;
	while(lca--)
	{
		int a,b;
		cin>>a>>b;
		cout<<lowestCommAnces(a,b)<<endl;
	}
}