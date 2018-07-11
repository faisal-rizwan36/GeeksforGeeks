#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

// creating Linked List
struct node *start = NULL;
struct node *createLL(int val)
{
	struct node *last = NULL;
	struct node* newnode = new node;
	newnode -> data = val;
	newnode ->next = NULL;
	if(start == NULL)
	{
		start->next = newnode;
		last = start;
	}
	else
	{
		last->next = newnode;
		last = last -> next;
	}
}

//main
int main (void)
{
	int n,val;
	cin>>n;
	while(n--)
	{
		cin>>val;
		createLL(val)
	}
}