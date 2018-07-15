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

struct node *segregate()
{
	struct node *odd = NULL , *even = NULL, *ptr = head, *evenhead = NULL, *oddhead = NULL, *currodd = NULL, *curreven = NULL;
	while(ptr != NULL)
	{
		if((ptr -> data) % 2 != 0)
		{
			cout<<ptr->data<<" odd \n";
			if(oddhead == NULL)
			{
				oddhead = odd;
				odd = ptr;
			}
			else
			{
				odd -> next = ptr;
				odd = odd -> next;
				odd -> next = NULL;
			}
		}
		else
		{
			cout<<ptr->data<<" even \n";
			if(evenhead == NULL)
			{
				evenhead = even;
				even = ptr;
			}
			else
			{
				even -> next = ptr;
				even = even -> next;
				even -> next = NULL;
			}
		}
		ptr = ptr -> next;
	}
	struct node *evenptr = evenhead;
	while(evenptr != NULL)
	{
		cout<<evenptr-> data<<" ";
		evenptr = evenptr -> next;
	}
	cout<<endl;
	struct node *oddptr = oddhead;
	while(oddptr != NULL)
	{
		cout<<oddptr-> data<<" ";
		oddptr = oddptr -> next;
	}
	cout<<endl;
	if(oddhead != NULL && evenhead != NULL)
	{
		cout<<(evenhead -> data)<<endl;
		cout<<(even -> data)<<endl;
		cout<<(oddhead -> data)<<endl;
		head = evenhead;
		even -> next = oddhead;
		odd -> next = NULL;
	}
/*	else if(oddhead == NULL && evenhead != NULL)
		head = evenhead;
	else if(evenhead == NULL && oddhead != NULL)
		head = oddhead;*/
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
	segregate();
	displayLL();
}