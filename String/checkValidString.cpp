/*
1. Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([)]"
Output: false

*/
#include<iostream>
#include<stack>
using namespace std;
bool isValid(string exp){
stack<char>s;
char x;
    for(int i=0;i<exp.length();i++)
    {

        if(exp[i]=='('||exp[i]=='['||exp[i]=='{'){
        s.push(exp[i]);
        continue;
        }
         if(s.empty())
            return false;

            switch(exp[i]){
                case ')':
                x=s.top();
                s.pop();
                if(x=='['||x=='{')
                return false;
                break;

                case ']':
                x=s.top();
                s.pop();
                if(x=='('||x=='{')
                  return false;
                break;

                case '}':
                x=s.top();
                s.pop();
                if(x=='('||x=='[')
                return false;
                break;
            }
        }
      // Check Empty Stack
      return (s.empty());
}
int main(){
    string exp;
    cin >> exp;
  if(isValid(exp)){
   cout<<"True";
  }
  else{
      cout<<"False";
  }
  return 0;
}