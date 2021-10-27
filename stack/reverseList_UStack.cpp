#include<iostream>
#include<stack>
using namespace std;
class Node{ 
    public:
    int data;
    Node * next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
class List{
    Node *head;
public:

    List():head(NULL){}
            Node * begin(){
                return head;
            }
void push(int data){
           if(head==NULL){
                Node* n=new Node(data);
                head =n;
            }
            else{
                Node* n=new Node(data);
                n->next=head;
                head=n;                
            }

}
 };
 Node *reverseList(Node * head){
   Node*ptr=head;
   stack<Node *>st;
   while(ptr->next!=NULL){
      st.push(ptr);
      ptr=ptr->next;
   }
   head=ptr;
   while(!st.empty()){
       ptr->next=st.top();
       ptr=ptr->next;
       st.pop();
   }
   ptr->next=NULL;
   return head;
}
void printList(Node *head){
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}
int main(){
    List l;
    l.push(5);
    l.push(4);
    l.push(3);
    l.push(2);
    l.push(1);
    Node *head=l.begin();
    cout<<"Print Linked List"<<endl;
    printList(head);
    cout<<endl;
    cout<<"After reversing the List : "<<endl;
    head = reverseList(head);
    printList(head);
}