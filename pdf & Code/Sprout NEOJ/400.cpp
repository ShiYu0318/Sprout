#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define x first
#define y second
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

struct Pt
{
    int x,y;
    Pt operator - (Pt b) {return {x - b.x, y - b.y};}
    int operator * (Pt b) {return x * b.x + y * b.y;}
    int operator ^ (Pt b) {return x * b.y - y * b.x;}
};

vector<Pt> v;

signed main()
{
    ShiYu;
    int n; cin >> n; v.resize(n);
    RPT(i,n) cin >> v[i].x >> v[i].y;
    int ans[3] = {0};
    RPT(i,n-2)
    {
        Pt o = v[i], a = v[i+1], b = v[i+2];
        int dot = (b - a) * (a - o),
            cross = (a - o) ^ (b - o);
        if(cross == 0)
        {
            if(dot < 0) ++ans[2];
        }
        else ++ans[cross < 0];
    }
    RPT(i,3) cout << ans[i] << " \n"[i == 2];
}