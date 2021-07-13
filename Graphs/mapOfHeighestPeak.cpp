class Solution
{
public:
    bool inside(int x, int y, int n, int m)
    {
        if (y >= 0 && y <= m - 1 && x >= 0 && x <= n - 1)
            return true;
        return false;
    }
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int n = isWater.size(), m = isWater[0].size();

        vector<vector<int>> height(n, vector<int>(m, -1));
        int row[] = {1, -1, 0, 0};
        int col[] = {0, 0, 1, -1};
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isWater[i][j] == 1)
                {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();

            int x = p.first, y = p.second;

            for (int k = 0; k < 4; k++)
            {
                int x1 = x + row[k];
                int y1 = y + col[k];
                if (inside(x1, y1, n, m))
                {
                    if (height[x1][y1] == -1)
                    {

                        height[x1][y1] = height[x][y] + 1;
                        q.push({x1, y1});
                    }
                }
            }
        }

        return height;
    }
};