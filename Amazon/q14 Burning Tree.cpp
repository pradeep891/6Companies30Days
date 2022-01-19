// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        if(root == nullptr)
        return 0;
        
        unordered_map< Node* , Node* >parentnode;
        queue< Node* >q;
        unordered_map< Node* , int >visited;
        q.push(root);
        Node* target1;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                Node* cur = q.front();
                q.pop();
                
                if(cur->data == target)
                target1 = cur;
                
                if(cur->left)
                {
                    q.push(cur->left);
                    parentnode[cur->left] = cur;
                }
                
                if(cur->right)
                {
                    q.push(cur->right);
                    parentnode[cur->right] = cur;
                }
            }
        }
        
        return solve(parentnode ,  target1);
    }
    
    int solve(unordered_map< Node* , Node* >&parentnode , Node* target)
    {
        queue<Node* >q;
        unordered_map< Node* , int> visited;
        
        q.push(target);
        visited[target] = 1;
        int tm = 0;
        
        while(!q.empty())
        {
            int n = q.size();
            int flag = 0;
            while(n--)
            {
                Node* cur = q.front();
                q.pop();
                
                // int flag = 0;
                if(cur->left && visited[cur->left] != 1)
                {
                    flag = 1;
                    visited[cur->left] = 1;
                    q.push(cur->left);
                }
                if(cur->right && visited[cur->right] != 1)
                {
                    flag = 1;
                    visited[cur->right] = 1;
                    q.push(cur->right);
                }
                if(parentnode[cur] && visited[parentnode[cur]] != 1)
                {
                    flag = 1;
                    visited[parentnode[cur]] = 1;
                    q.push(parentnode[cur]);
                }
            }
            if(flag)
                tm++;
            
        }
        
        return tm;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends