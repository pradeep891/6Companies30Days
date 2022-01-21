// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string ans = "";
        for(int i=0 ; i<s.size() ; i++)
        {
            char c = s[i];
            if(c <= 'Z' && c >= 'A')
            {
                if(i == 0)
                {
                    ans.push_back(c - 'A' + 'a');
                    continue;
                }
                ans.push_back(' ');
                ans.push_back(c - 'A' + 'a');
            }
            else
            ans.push_back(c);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends