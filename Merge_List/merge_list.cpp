#include <iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
   if (headA==NULL) return headB;
   if (headB==NULL) return headA;
       
   Node* list;
  if(headA->data < headB->data)
  {
      list = headA;
  }
  else
  {
      list = headB;
      headB = headA;
      headA = list;
  }
      

  while(headA->next != NULL && headB != NULL )
  {
    if(headA->next->data > headB->data)
    {
        Node* tmp = headA->next;
        headA->next = headB;
        headB = headB->next;
        headA->next->next= tmp;
    }
    
    headA=headA->next;
    
  }
  
   if (headB != NULL) headA->next = headB;
    
   return list;
      
  // This is a "method-only" submission. 
  // You only need to complete this method 
}

void Print(Node *head)
{
	bool ok = false;
	while(head != NULL)
	{
		if(ok)cout<<" ";
		else ok = true;
		cout<<head->data;
		head = head->next;
	}
        cout<<"\n";
}
Node* Insert(Node *head,int x)
{
   Node *temp = new Node();
   temp->data = x;
   temp->next = NULL;
   if(head == NULL) 
   {
       return temp;
   }
   Node *temp1;
   for(temp1 = head;temp1->next!=NULL;temp1= temp1->next);
   temp1->next = temp;return head;
}
int main()
{
	int t;
	cin>>t;
	while(t-- >0)
	{
		Node *A = NULL;
		Node *B = NULL;
		int m;cin>>m;
		while(m--){
			int x; cin>>x;
			A = Insert(A,x);}
		int n; cin>>n;
        while(n--){
			int y;cin>>y;
			B = Insert(B,y);
		}
		A = MergeLists(A,B);
		Print(A);
	}
}