#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data;
        node = node->next;
    }
    cout<<"\n";
}
class Solution
{
    public:
    //reverse the linked list
    Node* reverse(Node *head){
    Node* prev=NULL;
    auto curr=head;
    Node* nextp;
    while(curr!=NULL){
        nextp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextp;
    }
    head=prev;
    return head;
  }
    Node* addOneToIt(Node *head){
        //store the head ponter to the result
        auto res=head;
        //make another pointer
        Node* temp;

        int carry=1,sum;
        while(head!=NULL){
            //sum=data of current node plus carry value
            sum=head->data+carry;

            //if sum is more than 9 than assign 1 to the carry otherwise assign 0
            carry=(sum>=10)?1:0;
            //update sum
            sum=sum % 10;
            //update the current node
            head->data=sum;

            //update hea and temp
            temp=head;
            head=head->next;
        }
        if(carry>0){
            temp->next= new Node(carry);
        }
        return res;
    }
    Node* addOne(Node *head)
    {
        // first reverse the given list
       head=reverse(head);
       //start traversing from left node and add 1 to it .
       //if there is a carry move to the next node and keep moving to the next node
       //until there is a carry
       head =addOneToIt(head);
       //reverse back the array and return head pointer
       return reverse(head);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}
  // } Driver Code Ends
