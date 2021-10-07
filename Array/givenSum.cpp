#include<iostream>
#include<algorithm>
using namespace std;
void findSum(int arr[],int n,int target){

//O(n^2)
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        int sum=arr[i]+arr[j];
        if(sum==target)
          {   cout<<"Indices are : "<<endl;
              cout<<i<<" "<<j<<endl;
               return;
          }
    }
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
    int target;
    cout<<"Enter the target value"<<endl;
    cin>>target;
   findSum(arr,n,target);
}