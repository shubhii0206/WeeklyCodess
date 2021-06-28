//https://leetcode.com/problems/furthest-building-you-can-reach/

class Solution
{
public:
    int climbBuildings(vector<int> &heights, int idx, int bricks, int ladders)
    {
        if ((ladders <= 0 && bricks <= 0) || idx >= heights.size())
            return idx;

        if (heights[idx + 1] <= heights[idx])
            return 1 + climbBuildings(heights, idx + 1, bricks, ladders);

        if (ladders == 0)
        {
            if (idx + 1 < heights.size() && bricks >= heights[idx + 1] - heights[idx])
                return 1 + climbBuildings(heights, idx + 1, bricks - (heights[idx + 1] - heights[idx]), 0);
            else
                return 0;
        }
        else if (bricks == 0 && ladders > 0)
        {
            return 1 + climbBuildings(heights, idx + 1, 0, ladders - 1);
        }
        else if (ladders > 0 && bricks >= heights[idx + 1] - heights[idx])

            return max(1 + climbBuildings(heights, idx + 1, bricks - (heights[idx + 1] - heights[idx]), ladders), 1 + climbBuildings(heights, idx + 1, bricks, ladders - 1));
        else
            return 0;
    }
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {

        int cnt = 0;

        cnt = climbBuildings(heights, 0, bricks, ladders);
        return cnt;
    }
};


/===============================================================================/

The correct solution
    //https://leetcode.com/problems/furthest-building-you-can-reach/discuss/918374/Basic-Priority-Queue-Single-Pass-or-Code-with-Comments-or-Corner-Cases



     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
         int bricksUsed = 0; 
        priority_queue<int> brickNeeded;
        int reach =0;
        for(reach =0; reach < heights.size()-1; reach++)
        {
            int difference = heights[reach + 1] - heights[reach];
            
           if(difference < 0)
               continue;
                if(bricksUsed + difference <= bricks)
                {
                    bricksUsed += difference;
                    brickNeeded.push(difference);
                }
               else  if(ladders > 0){
                if(!brickNeeded.empty() && difference < brickNeeded.top())
                {   bricksUsed = bricksUsed - brickNeeded.top() + difference;
                  
                    brickNeeded.pop();
                    brickNeeded.push(difference);
                }
                ladders -= 1;}
            
            else 
                break;
        }
        
        return reach ;
        
        
    }
};