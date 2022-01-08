
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact1[], string s)
    {
        // code here
        vector<vector<string>>ans;
        sort(contact1 , contact1 + n);
        vector<string>contact;
        
        contact.push_back(contact1[0]);
        for(int i=1 ; i<n;i++)
        {
            if(contact1[i] != contact[i-1] )
            contact.push_back(contact1[i]);
        }
        
        // int start = 0 , end = contact.size()-1;
        
        map<string , vector<string> > mp;
        
        string p = "";
        for(int i=0 ; i<s.size() ; i++)
        {
            
            vector<string>v;
            
            if(i == 0)
            {
                
                p += s[i];
                for(int j=0 ; j<contact.size() ; j++)
                {
                    if(contact[j][0] == p[0] )
                    v.push_back(contact[j]);
                }
                
                if(v.size() == 0)
                v.push_back("0");
                
                mp[p] = v;
                
                ans.push_back(v);
                continue;
            }
            
            vector<string>find = mp[p];
            p += s[i];
            if(find.size() == 1 && find[0] == "0")
            {
                mp[p] = find;
                ans.push_back(find);
                continue;
            }
            
            
            for(int j=0 ; j<find.size() ; j++)
            {
                string kk = find[j];
                if(kk.substr(0 , i+1) == p)
                v.push_back(kk);
            }
            
            
            if(v.size() == 0)
            v.push_back("0");
            
            mp[p] = v;
            
            ans.push_back(v);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends