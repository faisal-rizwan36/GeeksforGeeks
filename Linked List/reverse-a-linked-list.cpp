#include <bits/stdc++.h>
using namespace std;

struct node 
{
	int data;
	struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

struct node *createLL(int val)
{
	struct node *newnode = new node;
	newnode -> data = val;
	newnode -> next = NULL;
	if(head == NULL)
	{
		head = newnode;
		tail = newnode;
	}
	else
	{
		tail -> next = newnode;
		tail = newnode;
	}
}

struct node *displayLL()
{
	struct node *ptr = head;
	while(ptr != NULL)
	{
		cout<<ptr -> data<<" ";
		ptr = ptr -> next;
	}
	cout<<endl;
}

struct node *reverse()
{
	struct node *postptr = NULL, *preptr = NULL;
	struct node *ptr = head;
	while(ptr != NULL)
	{
		postptr = ptr -> next;
		ptr -> next = preptr;
		preptr = ptr;
		ptr = postptr;

	}
	head = preptr;
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
	displayLL();
	reverse();
	displayLL();
}