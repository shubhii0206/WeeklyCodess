//https://leetcode.com/problems/keys-and-rooms/submissions/

class Solution
{
public:
    void dfs(int i, vector<bool> &visited, vector<vector<int>> &rooms)
    {
        visited[i] = true;
        for (auto x : rooms[i])
        {
            if (!visited[x])
                dfs(x, visited, rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {

        vector<bool> visited(rooms.size() + 1, false);

        dfs(0, visited, rooms);
        for (int i = 0; i < rooms.size(); i++)
        {
            cout << visited[i] << " ";
            if (!visited[i])
                return false;
        }

        return true;
    }
};