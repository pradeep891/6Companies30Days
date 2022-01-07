class Solution {
public:
    int minSubArrayLen(int target, vector<int>& num) {
        int left = 0 , len = num.size();
        
        long int sum = 0;
        int mn = INT_MAX;
       
        for(int i=0 ; i<len ; i++)
        {
            sum += num[i];
            while(sum >= target)
            {
                mn = min(mn, i+1 - left);
                sum -= num[left];
                left++;
            }
        }
        
        if(mn == INT_MAX)
            return 0;
        
        else
            return mn;
    }
};