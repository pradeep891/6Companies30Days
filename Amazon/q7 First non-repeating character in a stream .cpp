// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char>q;
		    unordered_map<char , int>ump;
		    string ans = "";
		    for(int i=0 ; i<A.size() ; i++)
		    {
		        if(i == 0)
		        {
		            q.push(A[i]);
		            ump[A[i]] = 1;
		            ans.push_back(A[i]);
		            continue;
		        }
		        
		        char ch  = A[i];
		        if(ump[ch] == 0)
		        {
		            ump[ch] = 1;
		            q.push(ch);
		        }
		        else
		        {
		            ump[ch]++;
		        }
		        while(!q.empty() && ump[q.front()] > 1)
		        q.pop();
		            
		        if(q.empty())
		            ans.push_back('#');
		        else
		            ans.push_back(q.front());
		    }
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends