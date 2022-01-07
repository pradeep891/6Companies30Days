#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , m , k;
    cin >> n >> m >> k;

    // cout << n << " " << m  << " " << k << "\n";
    int pos = m + k -1;
    pos = pos % n;

    if(pos == 0)
    cout << n;
    else
    cout << pos;
    return 0;
}