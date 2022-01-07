#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        unordered_map<string , vector<string> > mp;
        for(int i=0 ; i<string_list.size() ; i++)
        {
            string s = string_list[i];
            string p = s;
            sort(p.begin() , p.end());
            if(mp[p].size())
            {
                mp[p].push_back(s);
            }
            else
            {
                mp[p].push_back(s);
            }
        }
        vector<vector<string> >ans;
        // vector<string>an;
        
        for(auto i : mp)
        {
            ans.push_back(i.second);
        }
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
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends