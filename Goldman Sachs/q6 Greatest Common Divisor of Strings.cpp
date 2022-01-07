class Solution {
public:
    
    int gcd(int a , int b)
    {
        if(b == 0)
            return a;
        return gcd(a % b , a);
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1)
            return "";
        
        int k = __gcd(str1.size() , str2.size());
        
        string ans = str1.substr(0 , k);
        
        return ans;
        
    }
};