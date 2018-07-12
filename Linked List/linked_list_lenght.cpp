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
		tail = tail -> next;
	}
}

int lengthLL()
{
	int lenght = 0;
	struct node *ptr = head;
	while(ptr != NULL)
	{
		lenght++;
		ptr = ptr -> next;
	}
	return lenght;	
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
	cout<<lengthLL()<<endl;
}