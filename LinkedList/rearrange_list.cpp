#include <iostream>
using namespace std;
#include<iostream>
using namespace std;
template <typename T>
class List;
template<typename T>
class node{
    public:
    T data;
    node<T>*next;
    
    node(T d){
        data =d;
        next=NULL;
    }
    ~node(){
        if(next!=NULL){
            delete next;
        }
        cout<<"Deleted element is "<<data<<endl;
    }
    friend class List<T>;
};
template <typename T>
class List{
    node<T>*head;
    node<T>*tail;
    int searchHelper(node<T>*start,int key){
        if(start==NULL)
          return -1;
        int subidx;
        if(start->data==key){
            return 0;
        }
        else{
            subidx=searchHelper(start->next,key);
        }
        if(subidx==-1){
            return -1;
        }
        return subidx+1;
    }
public:
   List(){
       head=NULL;
       tail=NULL;
   }
   node<T>* begin(){
       return head;
   }
   //push at back of linked list
    void push_back(int data){
        node<T>*n=new node<T>(data);
        if(head==NULL){
            head=tail=n;
            return;
        }
        tail->next=n;
        tail=n;
        n=NULL;
    }
    //display linked list
    void display(){
      if(head ==NULL)
         return;
        node<T>*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }  
    }
    //pop from back of the linked list
        void pop_back(){
            if(head==NULL){ 
                return;
            }
            
            node<T>*temp=head;
            node<T>*n=NULL;
            while(temp->next!=NULL){
                n=temp;
                temp=temp->next;
            }
        tail=n;
        n->next=NULL;
        delete temp;

        }
    
};
node<int> * apend(node<int>* root,int d){
    if(root == NULL) return new node<int>(d);
    node<int>* temp = root;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new node<int>(d);
    return root;
}
node<int>* alternateMerge(node<int> * root1, node<int>* root2){
    
    node<int>* root = NULL;
    if(!root1) return root2;
    if(!root2) return root1;
    while(root1 && root2){
        root = apend(root, root1->data);
        root = apend(root, root2->data);
        root1 = root1->next;
        root2 = root2->next;
    }
    if(root1){
        while(root1){
            root = apend(root, root1->data);
            root1 = root1->next;
        }
    }
    if(root2){
        while(root2){
            root = apend(root, root2->data);
            root2 = root2->next;
        }
    }
    return root;
}

node<int> * reverse(node<int>*  head){
    node<int>*curr=head;
    node<int>*prev=NULL;
    node<int> *temp;
    while(curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}

void printList(node<int> *head){
    node<int>*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}



/*
  1.divide the array in two parts
  2.reverse the second part
  3.then alternatively merge both parts back to a single list 
  4.you will get desired output

*/
int main(){
List<int> l;
l.push_back(1);
l.push_back(2);
l.push_back(3);
l.push_back(4);
l.push_back(5);
l.push_back(6);
l.push_back(7);
node<int>*head=l.begin();
cout<<"<----------------------Original list--------------------->"<<endl;
printList(head);
node<int>*slow=head;
node<int>*fast=slow->next;
while (fast!=NULL and fast->next!=NULL)
{
    slow=slow->next;
    fast=fast->next->next;
}
node<int>*head1=head;
node<int>*head2=slow->next;
slow->next=NULL;
// printList(head1);
// printList(head2);
head2=reverse(head2);
// printList(head2);
head=alternateMerge(head1,head2);
cout<<"<----------------------------Rearranged list------------------------------>"<<endl;
printList(head);
return 0;

}