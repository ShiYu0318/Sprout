#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define endl '\n'
#define nl cout << '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; nl
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';

// 拓墣排序 裸題

const int MXN = 2e5+5;

void solve()
{
    priority_queue<int,vector<int>,greater<int>> q;
    vector<int> v[MXN], topo;
    int deg[MXN] = {0};
    // 輸入並建立 Edge 順便紀錄入度
    int n,m,a,b; cin >> n >> m;
    while(m--)
    {
        cin >> a >> b;
        v[a].EB(b);
        ++deg[b];
    }
    // 入度為 0 的推入 queue 當起點
    RPT(i,n) if(!deg[i]) q.emplace(i);
    // 不斷拔點
    while(!q.empty())
    {
        int now = q.top(); q.pop();
        topo.EB(now);
        for(auto i:v[now]) if(--deg[i] == 0) q.emplace(i);
    }
    if(topo.size() == n)
    {
        RPT(i,n) cout << topo[i] << " \n"[i == n-1];
    }
    else cout << "QAQ\n";
}

signed main()
{
    ShiYu;
    int t; cin >> t;
    while(t--) solve();
}