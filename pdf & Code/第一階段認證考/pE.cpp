#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define RPT(i,n) FOR(i,0,n)
#define F first
#define S second
#define pii pair<int,int>
#define all(x) x.begin(), x.end()
#define MP make_pair
#define EB emplace_back

void solve()
{
    // 亂寫 還有 5%
    int n; cin >> n;
    vector<int> v;
    int t;
    RPT(i,2*n)
    {
        cin >> t;
        if(t > 0) v.EB(t);
    }
    cout << n/2 << '\n';
    sort(all(v));
    for(auto i:v) cout << i << ' ';
    cout << '\n';
}


signed main()
{
    ShiYu;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}