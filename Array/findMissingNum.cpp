/*  Todays' question

Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:
Input: nums = [1,2,0]
Output: 3

Example 2:
Input: nums = [3,4,-1,1]
Output: 2

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1 
*/

#include<iostream>
#include<algorithm>
using namespace std;
int findSmallestMissingNum(int arr[],int n){

for(int i=0;i<n;i++){
    int correctPos=arr[i]-1;
    //this will place arr[i] at (i+1)th (as we have 0 based indexing) index ignoring the -ve elements and the elements which are greater than n
    if(1<=arr[i] and arr[i]<=n and arr[i]!=arr[correctPos]){
        swap(arr[i],arr[correctPos]);
        i--;
    } 
}
for(int i=0;i<n;i++){
    if(arr[i]!=i+1)
      return i+1;
}
return n+1;
}
int main(){
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter elements in array"<<endl;
    for(int i=0;i<n;i++)
     cin>>arr[i];
    
   cout<<findSmallestMissingNum(arr,n)<<endl;
}