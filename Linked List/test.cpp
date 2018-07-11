#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node *start = NULL;
struct node *last = NULL;

struct node *creatLL(int val)
{
	struct node *ptr, *newnode;
	newnode = new node;
	newnode -> next = NULL;
	newnode -> data = val;
	if(start == NULL)
	{
		start = newnode;
		last = start -> next;
	}
	else
	{
		ptr = start;
		while(ptr -> next != NULL)
			ptr = ptr -> next;
		ptr -> next = newnode;
		newnode -> next = NULL;
	}
}

struct node *display()
{
	struct node *ptr = start;
	while(ptr != NULL)
	{
		printf("%d ",ptr -> data);
		ptr = ptr -> next;
	}	
}
int main (void)
{
	int n,val;
	cin>>n;
	while(n--)
	{
		cin>>val;
		creatLL(val);
	}
	display();
}

