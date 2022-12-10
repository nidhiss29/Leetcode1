class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {     int oldColor = image[sr][sc];
        if(oldColor != newColor)
            dfs(image, sr, sc, newColor, oldColor);
        return image;
    }
    

    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor)
    { image[sr][sc] = newColor;
        
         if(sr > 0 && image[sr-1][sc] == oldColor) dfs(image, sr-1, sc, newColor, oldColor);
        if(sr < image.size()-1 && image[sr+1][sc] == oldColor) dfs(image, sr+1, sc, newColor, oldColor);
        if(sc > 0 && image[sr][sc-1] == oldColor) dfs(image, sr, sc-1, newColor, oldColor);
        if(sc < image[0].size()-1 && image[sr][sc+1] == oldColor) dfs(image, sr, sc+1, newColor, oldColor);