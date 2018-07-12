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

int getMiddle()
{
	struct node *ptr = head;
	struct node *fastptr = head;
	if(ptr == NULL)
		return -1;
	while(fastptr != NULL && fastptr -> next != NULL)
    {   
       ptr = ptr -> next;
       fastptr = fastptr -> next;
       fastptr = fastptr -> next;
    }
    return (ptr -> data);;	
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
	cout<<getMiddle()<<endl;
}