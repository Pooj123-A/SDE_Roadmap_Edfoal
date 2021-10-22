#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;

    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

//Main code
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    Node* detectLoop(Node* head)
    {Node*slow=head;
    Node*fast=head;

      while(fast!=NULL and fast->next!=NULL){
          slow=slow->next;
          fast=fast->next->next;
          if(slow==fast)
            return fast;
      }
      return nullptr;
    }
    int findStartingNode(Node* head){
    auto meet=detectLoop(head);
    auto start=head;
    int pos=1;
    while(meet!=start and meet->next!=start){
        pos++;
        start=start->next;
        meet=meet->next;
    }
    return pos;

    }
};

int main()
{

        int n, num;
        cin>>n;

        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);

        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin>> pos;
        loopHere(head,tail,pos);

        Solution ob;

        int pos1=ob.findStartingNode(head);
        cout<<"Loop started from "<<pos1<<endl;
	return 0;
}
