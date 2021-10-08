/*   Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:
Input: nums = [1]
Output: 1

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23

*/
#include<iostream>
#include<algorithm>
using namespace std;
int subArraySum(int arr[],int n){
    int maxSum=INT_MIN;
    int currSum=0;
    for(int i=0;i<n;i++){
        currSum+=arr[i];
        currSum=max(currSum,arr[i]);
        maxSum=max(currSum,maxSum);
    }
    return maxSum;
}
int main(){
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter elements in array"<<endl;
    for(int i=0;i<n;i++)
     cin>>arr[i];
     cout<<subArraySum(arr,n)<<endl;
}