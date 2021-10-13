#include<iostream>
#include<algorithm>
using  namespace std;

/* Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
*/

int minPath(int grid[][100],int i,int j,int m,int n){


    if(i==m-1 && j==n-1)
      return grid[i][j];

    if(i==m || j==n)
      return INT_MAX;

    return grid[i][j] + min ( minPath( grid, i, j+1, m, n), minPath(grid, i+1, j, m, n) );
}


int main()
{  
    
     int m,n;
    int mat[100][100]; 
    cin>>m>>n;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
   cout<< minPath(mat,0,0,m,n);
    // print(mat,m,n);
}