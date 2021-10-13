
#include<bits/stdc++.h>
using namespace std;

/* Given an m x n matrix, return all elements of the matrix in spiral order.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5] */
class Solution{
  public:
  
  void spiralMat(vector<vector<int>>arr,int row, int col){
      int rs=0,cs=0;
      int re=row-1;
      int ce=col-1;

   while(rs<=re && cs<=ce){

     for(int i=cs;i<=ce;i++)
        cout<<arr[rs][i]<<" ";

     rs++;

     for(int i=rs;i<=re;i++)
        cout<<arr[i][ce]<<" ";

     ce--;

     for(int i=ce;i>=cs;i--)
      {
          if(rs>re)
            break;
          cout<<arr[re][i]<<" ";
      }

    re--;

    for(int i=re;i>=rs;i--){
       if(cs>ce)
         break;
       cout<<arr[i][cs]<<" ";
    }
    cs++;
   }

  }

};
int main(){
    Solution obj;
    int row,col;
    cin>>row>>col;
    vector<vector<int>>arr(row,vector<int>(col));
    for(int i=0;i<row;i++)
       for(int j=0;j<col;j++)
         cin>>arr[i][j];
    obj.spiralMat(arr,row,col);
}