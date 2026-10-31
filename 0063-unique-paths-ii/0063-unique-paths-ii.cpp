class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;

        int arr[m][n];
        memset(arr, 0, sizeof(arr));   // zero every cell

        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 1) break;
            arr[0][i] = 1;
        }
        for (int j = 0; j < m; j++) {
            if (obstacleGrid[j][0] == 1) break;
            arr[j][0] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] != 1) arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
                else arr[i][j] = 0;
            }
        }
        return arr[m - 1][n - 1];
    }
};