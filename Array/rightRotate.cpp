/*  Today's Question


Given an array, rotate the array to the right by k steps, where k is non-negative.


Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

*/
#include<iostream>
#include<algorithm>
using namespace std;
void rightRotateArray(int arr[],int n, int r ){
    while(r>0){
        int temp=arr[n-1];
        for(int i=n-1;i>0;i--){
           arr[i]=arr[i-1];
         }
         arr[0]=temp;
         r--;
     }
}
int main(){
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter elements in array"<<endl;
    for(int i=0;i<n;i++)
     cin>>arr[i];
     int ele;
    cout<<"Enter a number by which you want to rotate the array: \n";
    cin>>ele;
    rightRotateArray(arr,n,ele);
    cout<<"Array after rotation: \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
   
}