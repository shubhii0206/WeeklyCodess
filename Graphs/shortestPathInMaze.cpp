class Solution
{
public:
    int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int col[8] = {1, 0, -1, -1, 1, -1, 0, 1};
    bool isValid(int x, int y, vector<vector<int>> &grid)
    {
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 0)
            return true;
        return false;
    }

    int shortestPath(int dest_x, int dest_y, vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        if (grid[0][0] == 1)
            return -1;
        q.push({0, 0});
        int dist = 1;

        while (!q.empty())
        {
            int s = q.size();
            while (s--)
            {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                if (x == dest_x && y == dest_y)
                    return dist;
                for (int i = 0; i < 8; i++)
                {
                    int xx = x + row[i];
                    int yy = y + col[i];

                    if (isValid(xx, yy, grid))
                    {
                        grid[xx][yy] = 1;
                        q.push({xx, yy});
                    }
                }
            }
            dist++;
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {

        int dest_x = grid.size() - 1, dest_y = grid[0].size() - 1;

        int dist = shortestPath(dest_x, dest_y, grid);
        return dist;
    }
};