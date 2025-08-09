#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define X first
#define Y second
#define EB emplace_back
#define endl '\n'
#define nl cout << '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define inputp(x) for(auto &i:x) cin >> i.X >> i.Y
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';

int vtlen(pii a, pii b)
{
    int x = a.X - b.X,
        y = a.Y - b.Y;
    return x*x + y*y;
}

signed main()
{
    ShiYu;
    int n; cin >> n;
    pii p[n];
    RPT(i,n) cin >> p[i].X >> p[i].Y;
    map<int,int> mp;
    RPT(i,n) FOR(j,i+1,n) ++mp[vtlen(p[i],p[j])];
    int ans = 0;
    for(auto i:mp) ans += i.Y * (i.Y-1) / 2;
    cout << ans << endl;
}