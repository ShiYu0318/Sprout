#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << "\n"
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define MP make_pair

// BFS struct

const int xy[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
struct grid{int x, y, round;};
queue<grid> q;
vector<string> tb;

int BFS()
{
    while (q.size())
    {
        auto [x,y,r] = q.front();
        RPT (i,4)
        {
            int nx = x + xy[i][0],
                ny = y + xy[i][1];
            if(tb[nx][ny] == '@') return r+1;
            if(tb[nx][ny] == '#') continue;
            q.emplace(grid{nx,ny,r+1});
            tb[nx][ny] = '#';
        }
        q.pop();
        // output(tb); cout << "\n";
    }
    return -1;
}

void solve()
{
    int n,m; cin >> n >> m;
    bool find = false; string s;
    RPT (i,n)
    {
        cin >> s; tb.EB(s);
        if (find) continue;
        RPT (j,m)
        {
            if (s[j] == 'K')
            {
                q.emplace(grid{i,j,0});
                tb[i][j] = '#';
                find = true;
                break;
            }
        }
    }
    int ans = BFS();
    if (ans != -1) cout << ans << "\n";
    else cout << "= =\"\n";
}

signed main()
{
    ShiYu
    int t; cin >> t;
    while (t--)
    {
        tb.clear();
        q = queue<grid>();
        solve();
    }
}