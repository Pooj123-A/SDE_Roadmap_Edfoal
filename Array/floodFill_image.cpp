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
#include<iostream>
#include<algorithm>
using namespace std;
int m,n;
int sr,sc;
int newColor;
int oldPixel;
int newPixel;
void floodFill(int image[190][100],int row,int column){
        if(row > m-1 || row<0){
            return;
        }

        if(column <0 || column> n-1){
            return;
        }

        if(image[row][column] == oldPixel){
            image[row][column] = newPixel;
            floodFill(image,row-1,column);
            floodFill(image,row+1,column);
            floodFill(image,row,column-1);
            floodFill(image,row,column+1);
        }
    }
int main(){
    
    cout<<"Enter number of rows and columns: "<<endl;
    cin>>m>>n;
    int image[m][n];
    cout<<"\nEnter elements in image matrix: \n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
         cin>>image[i][j];
    }
    
    cout<<"Enter sr: \n";
    cin>>sr;
    cout<<"Enter sc: \n";
    cin>>sc;
    
    oldPixel = image[sr][sc];

    cout<<"Enter new color"<<endl;
    cin>>newPixel;
    floodFill(image,sr,sc);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
         cout<<image[i][j]<<" ";
    cout<<endl;
    }
}