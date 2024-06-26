class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<=2) return points.size();
        int res = 0;
        for(int i = 0; i < points.size(); i++)
        {
            unordered_map<double, int> mp;
            double slope = 0.0;
            for(int j = 0; j < points.size(); j++)
            {
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];    
                
                int dy = y2 - y1;
                int dx = x2 - x1;
                if(dy == 0 && dx == 0){
                    continue;
                }
                
                if(dx != 0)
                    slope = dy*1.0/dx;
                else
                    slope = INT_MAX;
                
                mp[slope]++;
            }
            
            for(auto slope : mp){
                
                res = max(res, slope.second+1);
            }
        }
        return res;
    }
};