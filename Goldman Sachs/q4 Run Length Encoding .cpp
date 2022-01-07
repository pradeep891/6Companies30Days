#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  char pre = src[0];
  string ans = "";
  int ct = 0;
  for(int i=0 ; i<src.size() ; i++)
  {
      if(pre == src[i])
      {
          ct++;
      }
      
      else
      {
          ans = ans + pre + to_string(ct);
          pre = src[i];
          ct = 1;
      }
  }
  ans = ans + pre + to_string(ct);
  return ans;
}     
 
