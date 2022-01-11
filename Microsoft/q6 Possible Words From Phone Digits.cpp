// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string>v(10 , "");
        v[2] = "abc";
        v[3] = "def";
        v[4] = "ghi";
        v[5] = "jkl";
        v[6] = "mno";
        v[7] = "pqrs";
        v[8] = "tuv";
        v[9] = "wxyz";
        
        vector<string>ans;
        string s = "";
        solve(a , 0 ,  N  , ans , s , v);
        return ans;
    }
    void solve(int a[] , int i , int n , vector<string>&ans , string s , vector<string>&v)
    {
        if(i==n)
        {
            ans.push_back(s);
            return;
        }
        
        string k = v[a[i]];
        for(int j=0 ; j<k.size() ; j++)
        {
            s.push_back(k[j]);
            solve(a , i+1 , n , ans , s , v);
            s.pop_back();
        }
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends