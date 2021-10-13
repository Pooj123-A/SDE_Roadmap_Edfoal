#include<iostream>
#include<algorithm>
using namespace std;

/*
O(MAX * n * log n ) where n is the number of strings in the array and MAX is maximum number of characters in any string. comparison of two strings would take at most O(MAX) time and for sorting n strings, we would need O(MAX * n * log n ) time.

string  longestPrefix(string str[],int n){
      if(n==0)
        return "";
      if(n==1)
        return str[0];
      sort(str,str+n);
       for(int i=0;i<n;i++)
         cout<<str[i]<<" ";
       cout<<endl;
      int len=min(str[0].size(),str[n-1].size());
      string first=str[0],last=str[n-1];
      int i=0;
      while(i<len and first[i]==last[i])
        i++;
    if(i==0)
      return "-1";
    string s = first.substr(0,i);
    return s;
}

int main(){
int n;
cin>>n;
string str[n];

for(int i=0;i<n;i++)
  cin>>str[i];

string s=longestPrefix(str,n);
cout<<"Longest prefix is : "<<endl;
cout<< s <<endl;
}

*/


string commonPrifixTillNow(string str1,string str2){
    int n1=str1.length(),n2=str2.length();
     string result;
     for(int i=0,j=0;i<n1 and j<n2;i++,j++){
         if(str1[i]!=str2[j])
           break;
        result.push_back(str1[i]);
     }
    return result;
}
string longestPrefix(string str[],int n){
string prefix=str[0];
for(int i=1;i<n;i++){
   prefix= commonPrifixTillNow(prefix,str[i]);   
}
return prefix;
}
int main(){
int n;
cin>>n;
string str[n];

for(int i=0;i<n;i++)
  cin>>str[i];

string s=longestPrefix(str,n);
cout<<"Longest prefix is : "<<endl;
cout<< s <<endl;
}