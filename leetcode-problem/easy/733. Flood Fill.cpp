class Solution {
public:
    void DFS(vector<vector<int>>& image, int x, int y, int oldColor, int newColor)
    {
        if(image[y][x] == oldColor)
        {
            image[y][x] = newColor;
            if(x > 0)
                DFS(image, x - 1, y, oldColor, newColor);
            if(x < image[0].size() - 1)
                DFS(image, x + 1, y, oldColor, newColor);
            if(y > 0)
                DFS(image, x, y - 1, oldColor, newColor);
            if(y < image.size() - 1)
                DFS(image, x, y + 1, oldColor, newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor)
            return image;
        DFS(image, sc, sr, image[sr][sc], newColor);
        return image;
    }
};