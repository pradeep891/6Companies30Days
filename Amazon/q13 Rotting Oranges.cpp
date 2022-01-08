class Solution {
public:
    bool norotten(vector<vector<int>>& grid)
    {
        for(int i=0 ; i<grid.size() ; i++)
        {
            for(int j=0 ; j<grid[i].size() ; j++)
            {
                if(grid[i][j] == 2)
                    return false;
            }
        }
        return true;
    }
    
    bool allrotten(vector<vector<int>>& grid)
    {
        for(int i=0 ; i<grid.size() ; i++)
        {
            for(int j=0 ; j<grid[i].size() ; j++)
            {
                if(grid[i][j] == 1)
                    return false;
            }
        }
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        //no rotten return -1
        //all rotten return 0 
        
        if(allrotten(grid))
            return 0;
        
        if(norotten(grid))
            return -1;
        
        
        int ct = 0;
            int m = grid.size();
            int n = grid[0].size();
        
        while(1)
        {
            // cout << "he";
            vector<vector<int>> naya = grid;
            for(int i=0 ; i<m; i++)
            {
                for(int j=0 ; j<n ; j++)
                {
                    if(grid[i][j] == 2)
                    {
                        if(i-1 >=0 && grid[i-1][j] == 1)
                            naya[i-1][j] = 2;
                        if(i+1 < m && grid[i+1][j] == 1)
                            naya[i+1][j] = 2;
                        if(j-1 >=0 && grid[i][j-1] == 1)
                            naya[i][j-1] = 2;
                        if(j+1 < n && grid[i][j+1] == 1)
                            naya[i][j+1] = 2;
                    }
                }
            }
            
            if(grid == naya)
            {
                break;
            }
            else
            {
                grid = naya;
                ct++;
            }
        }
        if(allrotten(grid))
        return ct;
        else
            return -1;
    }
};