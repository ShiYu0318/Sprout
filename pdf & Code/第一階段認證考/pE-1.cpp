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
    // 亂寫 subtask.1 10%
    int n; cin >> n;
    int a,b,c,d; cin >> a >> b >> c >> d;
    if(a == -b) cout << 0 << '\n' << c << ' ' << a << '\n';
    else if(b == -c) cout << 0 << '\n' << a << ' ' << b << '\n';
    else cout << 1 << '\n' << a << ' ' << b << '\n';
}


signed main()
{
    ShiYu;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}