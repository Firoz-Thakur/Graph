An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.


https://leetcode.com/problems/flood-fill/



  int n,ch,m;
   const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    
    void help(vector<vector<int>>& image,int sr,int sc,int cl)
    {
       
        
       if(sr<0 || sc<0 || sr>=n || sc>=m ||  image[sr][sc]!=ch || image[sr][sc]==cl)
            return;
         
      image[sr][sc]=cl;
      for(int k=0;k<4;k++)
      {
          help(image,sr+dx[k],sc+dy[k],cl);
      }

    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)     {
      n=image.size();
      m=image[0].size();
      ch =image[sr][sc]; 
      help(image,sr,sc,newColor);   

      return image;  
    }
