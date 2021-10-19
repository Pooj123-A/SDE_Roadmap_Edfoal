#include<iostream>
#include "list_ll.h"
using namespace std;
int main(){
List<int> l;
for(int i=10;i<=100;i+=10){
    l.push_front(i);
}
cout<<"-----------------------------------------------"<<endl;
l.display();

List<int> l1;
for(int i=10;i<=100;i+=10){
    l1.push_back(i);
}
cout<<"-----------------------------------------------"<<endl;
l1.display();
l1.pop_back();
l1.display();
// l1.remove();
cout<<"Element present at index= "<<l1.search(90)<<endl;
cout<<"Element present at index= "<<l1.recursiveSearch(80)<<endl;
cout<<l1.getNode(7)<<endl;
cout<<l1.length()<<endl;
l1.deleteAtPos(8);
//l1.display();
l1.insert(300,3);
l1.deleteValue(40);
l1.display();
l1.pop_front();
l1.remove();
}