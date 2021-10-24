/*
     Just for practicing arrays
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.

 

Example 1:
Input: nums = [1,3,5]
Output: 1

Example 2:
Input: nums = [2,2,2,0,1]
Output: 0


*/
#include<iostream>
#include<algorithm>
using namespace std;
int findSmallestInRotateArray(int arr[],int N){
    int lo=0;
    int hi=N-1;
    if(arr[lo]<arr[hi]){
        return arr[0];
    }
    int mid,prev,next;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        prev=(mid+N-1)%N;
        next=(mid+1)%N;
        
        //check if mid is smallest element or not
        if(arr[mid]<=arr[next] && arr[mid]<=arr[prev]){
            return arr[mid];
        }

        //otherwise minimum element will be present in unsorted part of the given array
        else if(arr[0]<=arr[mid]){
            lo=mid+1;
        }
        else if(arr[mid]<=arr[N-1]){
            hi=mid-1;
        }

     }
     return -1;
}

int main(){
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter elements in array"<<endl;
    for(int i=0;i<n;i++)
     cin>>arr[i];
   int s= findSmallestInRotateArray(arr,n);
   cout<<"Smallest element is "<<s<<endl;
   return 0;
}