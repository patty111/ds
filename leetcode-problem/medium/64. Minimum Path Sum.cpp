#include <limits.h>
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int** record = new int*[m];
        for (int i=0; i<m; ++i)
            record[i] = new int[n]{INT_MAX};

        record[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i)
            record[i][0] = record[i-1][0] + grid[i][0];
        for (int i = 1; i < n; ++i)
            record[0][i] = record[0][i-1] + grid[0][i];
        

        for (int i=1; i<m; ++i)
            for (int j=1; j<n; ++j)
                record[i][j] = min(record[i-1][j], record[i][j-1]) + grid[i][j];

        return record[m-1][n-1];
    }
};