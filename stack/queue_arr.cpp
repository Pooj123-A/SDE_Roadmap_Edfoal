#include<iostream>
using namespace std;
template<typename T>
class Queue{
T *arr;
int cs;
int ms;
int front;
int rear;
public:
Queue(int default_size=5){
    ms=default_size;
    cs=0;
    arr=new T[ms];
    front=0;
    rear=ms-1;
}
bool isFull(){
    return cs==ms;
}
bool isEmpty(){
    return cs==0;
}
void push(T data){
    if(!isFull()){
        //take the rear to the next index
        rear=(rear+1)%ms;
        arr[rear]=data;
        cs++;
    }
}
void pop(){
    if(!isEmpty()){
        //take front pointer forward 
        front=(front+1)%ms;
        cs--;
    }
}
T atFront(){
    if(!isEmpty())
        return arr[front];
    
}
};
int main(){
    Queue<string>books(5);
    books.push("c++");
    books.push("Java");
    books.push("Python");
    books.push("Dbms");
    books.push("Operating System");
    while(!books.isEmpty()){
        cout<<books.atFront()<<endl;
        books.pop();
    }
    return 0;
}