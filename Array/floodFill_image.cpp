/*

Another One

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
Output: [[2,2,2],[2,2,2]]
 

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], newColor < 216
0 <= sr < m
0 <= sc < n 

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

  void findColor(vector<vector<int>>& image,int row,int col,int newColor,int oldColor){
       
       if(row<0 || row>=image.size())
         return;
       if(col<0||col>=image[0].size())
         return;
       
       
       if(image[row][col]!=oldColor)
           return;
       
        if(image[row][col]==newColor)
          return;
         
           image[row][col]=newColor;
           
         findColor(image,row-1,col,newColor,oldColor);
         findColor(image,row+1,col,newColor,oldColor);
         findColor(image,row,col+1,newColor,oldColor);
         findColor(image,row,col-1,newColor,oldColor);
       
      
   }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        int oldColor=image[sr][sc];
       if(newColor==oldColor)
         return image;
       findColor(image,sr,sc,newColor,oldColor);
       return image;
    }
};


int main(){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	
	return 0;
}  

  