// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int isValid(vector<vector<int>> A){
        
        
        unordered_map<int,int> row,col,block;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(A[i][j]!=0){
            if(row[A[i][j]]==0)
                row[A[i][j]]++;
            else
                return 0;
            }
            if(A[j][i]!=0){
            if(col[A[j][i]]==0)
                col[A[j][i]]++;
            else    
                return 0;
            }
        }
        col.clear();
        row.clear();
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
             if(A[i][j]!=0){
            if(block[A[i][j]]==0)
                block[A[i][j]]++;
            else
                return 0;
             }
        }
    }
        block.clear();
    for(int i=0;i<3;i++)
    {
        for(int j=3;j<6;j++)
        {
             if(A[i][j]!=0){
            if(block[A[i][j]]==0)
                block[A[i][j]]++;
            else
                return 0;
             }
        }
    }
        block.clear();
    for(int i=0;i<3;i++)
    {
        for(int j=6;j<9;j++)
        {
             if(A[i][j]!=0){
            if(block[A[i][j]]==0)
                block[A[i][j]]++;
            else
                return 0;
             }
        }
    }
      block.clear();
    
    for(int i=3;i<6;i++)
    {
        for(int j=0;j<3;j++)
        {
             if(A[i][j]!=0){
            if(block[A[i][j]]==0)
                block[A[i][j]]++;
            else
                return 0;
             }
        }
    }
        block.clear();
     for(int i=3;i<6;i++)
    {
        for(int j=3;j<6;j++)
        {
             if(A[i][j]!=0){
            if(block[A[i][j]]==0)
                block[A[i][j]]++;
            else
                return 0;
             }
        }
    }
        block.clear();
     for(int i=3;i<6;i++)
    {
        for(int j=6;j<9;j++)
        {
             if(A[i][j]!=0){
            if(block[A[i][j]]==0)
                block[A[i][j]]++;
            else
                return 0;
             }
        }
    }
        block.clear();
    
    for(int i=6;i<9;i++)
    {
        for(int j=0;j<3;j++)
        {
             if(A[i][j]!=0){
            if(block[A[i][j]]==0)
                block[A[i][j]]++;
            else
                return 0;
             }
        }
    }
        block.clear();
     for(int i=6;i<9;i++)
    {
        for(int j=3;j<6;j++)
        {
             if(A[i][j]!=0){
            if(block[A[i][j]]==0)
                block[A[i][j]]++;
            else
                return 0;
             }
        }
    }
        block.clear();
     for(int i=6;i<9;i++)
    {
        for(int j=6;j<9;j++)
        {
             if(A[i][j]!=0){
            if(block[A[i][j]]==0)
                block[A[i][j]]++;
            else
                return 0;
             }
        }
    }   
    return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends