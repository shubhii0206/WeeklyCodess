/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution
{
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals)
    {

        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b)
             {
                 if (a.start != b.start)
                     return a.start < b.start;
                 return a.end < b.end;
             });
        priority_queue<int, vector<int>, greater<int>> pq;
        int cnt = 0;

        for (int i = 0; i < intervals.size(); i++)
        {
            pq.push(intervals[i].end);
            if (intervals[i].start < pq.top())
                cnt++;
            else
                pq.pop();
        }

        return cnt;
    }
};
