
class Solution
{
public:
    int dfs(vector<vector<int>> &mat, int i, int j, int m, int n)
    {
        if (i >= m || i < 0 || j >= n || j < 0 || mat[i][j] == -2)
            return 10000;

        if (mat[i][j] == 0 || mat[i][j] == 1)
            return mat[i][j];
        int dis = mat[i][j];
        mat[i][j] = -2;

        dis = 1 + min({dfs(mat, i + 1, j, m, n), dfs(mat, i - 1, j, m, n), dfs(mat, i, j + 1, m, n), dfs(mat, i, j - 1, m, n)});

        mat[i][j] = dis;
        return dis;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {

        int m = mat.size(), n = mat[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                    mat[i][j] = 10000;
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dfs(mat, i, j, m, n);
            }
        }

        return mat;
    }
};