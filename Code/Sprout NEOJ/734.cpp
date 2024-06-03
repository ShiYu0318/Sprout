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

// MST + DSU + 路徑壓縮 + 啟發式合併

struct Edge{int a,b,w;};
bool cmp(Edge a, Edge b) {return a.w < b.w;}
vector<int> lead, cnt;
int ans, edge_cnt;

int find(int x)
{
    return (lead[x] == x ? x : lead[x] = find(lead[x]));
}

void join(Edge e)
{
    int a = find(e.a), b = find(e.b);
    if(a == b) return;
    if(cnt[a] < cnt[b]) swap(a,b);
    cnt[a] += cnt[b];
    lead[b] = a;
    ans += e.w;
    ++edge_cnt;
}

signed main()
{
    ShiYu;
    int n,m; cin >> n >> m;
    lead.resize(n+1); cnt.resize(n+1,1); iota(all(lead),0);
    vector<Edge> e(m);
    RPT(i,m) cin >> e[i].a >> e[i].b >> e[i].w;
    sort(all(e), cmp);
    for(int i=0; i<m && edge_cnt<n; ++i) join(e[i]);
    // if(edge_cnt != n-1)
    cout << ans << endl;
}