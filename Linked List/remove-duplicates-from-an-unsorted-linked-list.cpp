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
	newnode -> data =  val;
	newnode -> next = NULL;
	if(head == NULL)
	{
		head = newnode;
		tail = newnode;
	}
	else
	{
		tail -> next = newnode;
		tail = tail -> next;
	}
}

struct node *displayLL()
{
	struct node *ptr = head;
	while(ptr != NULL)
	{
		cout<<ptr->data<<" ";
		ptr = ptr -> next;
	}
	cout<<endl;
}

struct node *removeDup()
{
	map<int, int> m;
	struct node *ptr = head -> next;
	struct node *prev = head;
	m[prev -> data]++;
	while(ptr != NULL)
	{
		m[ptr -> data]++;
		if(m[ptr->data] >= 2)
		{
			if(ptr -> next == NULL)
			{
				prev -> next = NULL;
			}
			else
			{
				prev -> next = ptr -> next;
			}
			ptr =  prev -> next;		
		}
		else
		{
			m[ptr->data]++;
			prev = prev -> next;
			ptr = ptr -> next;
		}
	}
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
	removeDup();
	displayLL();
}