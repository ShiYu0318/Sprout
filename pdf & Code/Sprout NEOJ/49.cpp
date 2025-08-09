#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
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

const int SP = 1e5+5;
vector<int> v[SP];
bool placed[SP];
int ans[SP];

int Count(int n)
{
    int sum = 1;
    RPT(i,SZ(v[n]))
    {
        sum += Count(v[n][i]);
    }
    ans[n] = sum;
    return sum;
}

signed main()
{
    ShiYu;
    int t,n,m,x,y,q,w; 
    cin >> t; 
    while(t--)
    {
        cin >> n >> m;
        RPT(i,SP)
        {
            v[i].clear();
            placed[i] = false;
            ans[i] = 0;
        }
        RPT(i,m)
        {
            cin >> x >> y;
            v[x].EB(y);
            placed[y] = true;
        }
        FOR(i,1,n+1)
        {
            if(!placed[i]) Count(i);
        }
        cin >> q;
        while(q--)
        {
            cin >> w;
            cout << ans[w] << '\n';
        }
    }
}