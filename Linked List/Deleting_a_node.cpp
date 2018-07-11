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

struct node *deletekey(int key)
{
	struct node *ptr = head;
	struct node *prev = head;
	while(ptr != NULL)
	{
		if(ptr -> data == key && ptr == head)
		{
			head = ptr -> next;
			free(ptr);
			break;
		}
		else if(ptr -> data == key)
		{
			prev -> next = ptr -> next;
			free(ptr);
			break;
		}
		prev = ptr;
		ptr = ptr -> next;
	}

}

int main (void)
{
	int n,val,key;
	cin>>n;
	while(n--)
	{
		cin>>val;
		createLL(val);
	}
	displayLL();
	cin>>key;
	deletekey(key);
	displayLL();
}