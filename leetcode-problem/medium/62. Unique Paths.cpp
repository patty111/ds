class Solution {
public:
    int uniquePaths(int m, int n) {
        int** grids = new int*[m];
        for (int i=0; i<m; ++i){
            grids[i] = new int[n];
            grids[i][0] = 1;
        }

        for (int i=0; i<n; ++i)
            grids[0][i] = 1;

        for (int i=1; i<m; ++i){
            for (int j=1; j<n; ++j){
                grids[i][j] = grids[i-1][j] + grids[i][j-1];
            }
        }

        return grids[m-1][n-1];
    }
};