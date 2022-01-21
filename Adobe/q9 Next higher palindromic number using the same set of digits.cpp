//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
  
    string nextPalin(string N) { 
        //complete the function here
        int l = N.size();
        
        if(l < 4)
        return "-1";
        
        
        int start = -1 , end = -1;
        for(int i=l/2-1 ; i>0 ; i--)
        {
            if(N[i] <= N[i-1])
            continue;
            
            else
            {
                start = i-1;
                break;
            }
        }
        
        // cout << start << " ";
        if(start == -1)
        return "-1";
        
        string k = "";
        for(int i=start+1 ; i<l/2 ; i++)
        {
            k += N[i];
        }
        
        sort(k.begin() , k.end());
        char ch ;
        for(int i=0 ; k.size() ; i++)
        {
            if(N[start] < k[i])
            {
                ch = k[i];
                break;
            }
        }
        
        for(int i=start+1 ; i<l/2 ; i++)
        {
            if(ch == N[i])
            {
                end = i;
            }
        }
        
        swap(N[start] , N[end]);
        string ans = N.substr(0 , start+1);
        string p = N.substr(start+1 , l/2-start-1);
        sort(p.begin() , p.end());
        
        ans = ans + p ; //+ p2;
        // cout << "ans = " << ans << endl;
        
        if(l % 2 == 1)
        {
            string qq = ans + N[l/2];
            reverse(ans.begin() , ans.end());
            return qq + ans;
        }
        else
        {
            string qq = ans;
            reverse(ans.begin() , ans.end());
            return qq + ans;
        }
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends