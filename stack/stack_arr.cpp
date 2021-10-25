#include<iostream>
using namespace std;
template<typename T>
class  Stack{
T *arr;
int cs;
int ms;
int top;
public:
  Stack(int default_size=5){
     ms=default_size;
     cs=0;
    arr=new T [ms];
    top=-1;
  }
  bool isEmpty(){
    return cs==0;
  }
  bool isFull(){
      return cs==ms;
  }
  void push(T data){
      if(!isFull()){
          top++;
          arr[top]=data;
          cs++;
      }
  }
  void pop(){
      if(!isEmpty()){
          top--;
          cs--;
      }
  }
  T atTop(){
      return arr[top];
  }
};
int main(){
    Stack<char> s;
    s.push('H');
    s.push('e');
    s.push('l');
    s.push('l');
    s.push('o');
    while(!s.isEmpty()){
        cout<<s.atTop()<<endl;
        s.pop();
    }
}