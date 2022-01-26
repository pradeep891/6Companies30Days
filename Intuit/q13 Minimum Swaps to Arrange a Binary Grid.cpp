class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int>num;
        for(int i=0 ; i<grid.size() ; i++)
        {
            num.push_back(solve(grid[i]));
        }
        int n = num.size();
        
        //sort
        int sp = 0;
        for(int i=0 ; i<n ; i++)
        {
            int k = n-i-1;
            if(num[i] >= k)
                continue;
            
            int id = -1;
            for(int j = i+1 ; j<n ; j++)
            {
                if(k <= num[j] )
                {
                    id = j;
                    break;
                }                
            }
            
            if(id == -1)
                return -1;
            
            for(int j = id ; j>i ; j--)
            {
                swap(num[j] , num[j-1]);
                sp++;
            }            
        }
        
        return sp;
    }
    int solve(vector<int>v)
    {
        int ct = 0;
        int l = v.size();
        for(int i=l-1 ; i>=0 ; i--)
        {
            if(v[i] == 0)
                ct++;
            else
                return ct;
        }
        return ct;
    }
};