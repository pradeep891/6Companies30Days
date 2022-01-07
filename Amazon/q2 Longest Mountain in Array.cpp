class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int ans = 0;
        for(int i=1 ; i<arr.size() - 1 ; i++)
        {
            int left = i;
            int right = i;
            
            int ct1 = 0 , ct2 = 0;
            while(left-1 >= 0 && arr[left] > arr[left-1] )
            {
                ct1++;
                left--;
            }
            while(right+1 <= arr.size()-1 && arr[right] > arr[right+1] )
            {
                ct2++;
                right++;
            }
            
            if(ct1 > 0 && ct2 > 0)
            ans = max(ans , ct1+ct2+1);
        }
        return ans;
    }
};