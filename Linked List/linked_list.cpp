#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *next;	
};

struct node *start = NULL;
struct node *tail = NULL;

struct node *createLL(int val)
{
	struct node *newnode = new node;
	newnode -> next = NULL;
	newnode -> data = val;
	if(start == NULL)
	{
		start = newnode;
		tail = start;
	}
	else
	{
		tail -> next = newnode;
		tail = tail -> next;
	}
}

struct node *DisplayLL()
{
	while(start != NULL)
	{
		cout<<start->data<<" ";
		start = start -> next;
	}
	cout<<endl;
}

int main (void)
{
	int n,val;
	cin>>n;
	while(n--)
	{
		cin>>val;
		createLL(val);
	}
	DisplayLL();
}