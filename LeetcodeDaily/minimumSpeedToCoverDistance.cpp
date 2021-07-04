//https://leetcode.com/problems/minimum-speed-to-arrive-on-time/submissions/
class Solution
{
public:
    int minimumSpeed(vector<int> &dist, double hour)
    {
        int low = 1, high = 10000001;
        while (low < high)
        {
            int mid = (low + high) / 2;

            if (canCoverDistance(mid, dist, hour))
                high = mid;
            else
                low = mid + 1;
        }

        return high;
    }
    bool canCoverDistance(int speed, vector<int> &dist, double hour)
    {
        double time_taken = 0.0, i;
        for (i = 0; i < dist.size() - 1; i++)
        {
            double time = (double)dist[i] / (double)(speed);
            time_taken += ceil(time);
        }
        time_taken += (double)dist[i] / (double)(speed);
        return time_taken <= hour;
    }
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int p = minimumSpeed(dist, hour);
        if (p >= 10000001)
            return -1;
        return p;
    }
};