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

bool getLoop()
{
	struct node *ptr = head;
	struct node *fastptr = head;
	while((ptr != NULL) || (fastptr != NULL && fastptr -> next != NULL))
    {   
       if(ptr == fastptr)
       		return true;
       ptr = ptr -> next;
       fastptr = fastptr -> next -> next;
    }
    return false;	
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
	int ans = getLoop();
	if(ans)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
}