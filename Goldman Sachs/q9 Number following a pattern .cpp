// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    void reversee(string &ans , int i , int j)
    {
        while(i < j)
        {
            swap(ans[i] , ans[j]);
            i++;
            j--;
        }
    }
    
    string printMinNumberForPattern(string s){
        // code here 
        string ans = "";
        for(int i=0 ; i<=s.size() ; i++)
        {
            ans.push_back('0' + i+1);
        }
        int i = 0; 
        int ct = 0;
        for(i=0 ; i<s.size() ; i++)
        {
            char ch = s[i];
            if(ch == 'D')
            {
                ct++;
            }
            else
            {
                if(ct == 0)
                continue;
                else
                {
                    reversee(ans , i-ct , i);
                    ct = 0;
                }
            }
        }
        if(ct > 0)
        reversee(ans ,  i-ct , i);
        return ans;
        
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends