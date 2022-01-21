// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int ans = 0 , p =1;
        for(int i = 0 ; i<str.size() ; i++)
        {
            if(!isdigit(str[i]))
            {
                if(i == 0 && str[i] == '-')
                {
                    p = -1;
                    continue;
                }
                else
                return -1;
            }
            
            ans = ans*10 + str[i] - '0';
        }
        return ans * p;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends