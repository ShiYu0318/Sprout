#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << " "
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

// stack 列車

signed main()
{
    ShiYu
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> v(n); input(v);
        stack<int> s;
        int now = 0;
        FOR(i,1,n+1)
        {
            s.emplace(i);
            while(!s.empty() && s.top() == v[now])
            {
                s.pop();
                ++now;
            }
        }
        Yn(s.empty());
    }
}
