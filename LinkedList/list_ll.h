// 1. Linked List Insertion & Displaying the LinkedList
// 2. Linked List Deletion (Deleting a given key)
// 3. Linked List Deletion (Deleting a key at given position)
// 4. Write a function to delete a Linked List
// 5. Find Length of a Linked List (Iterative and Recursive)
// 6. Search an element in a Linked List (Iterative and Recursive)
// 7. Write a function to get Nth node in a Linked List
#include<iostream>
using namespace std;
template <typename T>
class List;
template<typename T>
class node{
    T data;
    node<T>*next;
    public:
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
// 1. Linked List Insertion & Displaying the LinkedList
  //push at front of linked list
   void push_front(T data){
        node<T>*n=new node<T>(data);
       if(head==NULL){
            head=tail=n;
            return;  
        }
       n->next=head;
       head=n;     
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
      //delete node from front of linked list
        void  pop_front(){
            if(head==NULL){ 
                return;
            }
            else{
            node<T>*temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
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
// 2. Linked List Deletion (Deleting a given key)
     void deleteValue(int key){
       node<T>*curr=head;
       node<T>*prev=NULL;
       while(curr!=NULL){
           if(curr->data==key){
              prev->next=curr->next;
              curr->next=NULL;
              delete curr;

           }
           prev=curr;
           curr=curr->next;
       }
     }
    //insert at after given position
     void insert(int data,int pos){
         if(pos<0)
             return;
        if(pos==0){
                push_front(data);
                return;
            }
        node<T>*temp=head;

        for(int jump=1;jump<=pos-1;jump++){
            temp=temp->next;
        }
        node<T>*n=new node<T>(data);
        n->next=temp->next;
        temp->next=n;
        
     }
// 3. Linked List Deletion (Deleting a key at given position)
void deleteAtPos(int pos){
         if(pos<0)
             return;
        if(pos==1){
                pop_front();
                return;
            }
        node<T>*temp=head;
        node<T>*prev=NULL;
        for(int jump=1;jump<=pos-1;jump++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        temp->next=NULL;
        delete temp;     
     }
// 4. Write a function to delete a Linked List

// 5. Find Length of a Linked List (Iterative and Recursive)
    int length(){
        if (head==NULL)
          return 0;
        node<T>*temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }


    
    //6.Search an element in a Linked List Iterative
     int search(int key){
       node<T>*temp=head;
       int idx=1;
       while(temp!=NULL){
           if(temp->data==key){
               return idx;
           }
           temp=temp->next;
           idx++;
       }
       return -1;
     }
     //Search an element in a Linked List Recursive
     int recursiveSearch(int key){
            int idx=searchHelper(head,key);
            return idx+1;
    }
     
// 7. Write a function to get Nth node in a Linked List
int  getNode(int N){
    node<T>*temp=head;
        if(N<=0 || N>length())
             return -1;

        for(int jump=1;jump<=N-1;jump++){
            temp=temp->next;
        }
       return temp->data;
}


     // 4. Write a function to delete a Linked List
     void remove(){
         if(head==NULL)
           return;
       delete head;
     }

//    ~List(){
//             //1.Loop
//             if(head!=NULL){
//                 delete head;
//                 head=NULL;
//             }
//     }

};