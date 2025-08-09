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
#define RPT1(i,n) for(int i=1; i<=n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; nl
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define outputD(x,a,b) RPT(i,a) RPT(j,b) cout << x[i][j] << " \n"[j == b-1]
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define clear_arr(x) memset(x,0,sizeof(x))

// BFS

const int SP = 1e3+5, dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
bool tb[SP][SP], vis[SP][SP];
queue<pii> q;

void BFS(int x, int y)
{
    q.emplace(x,y);
    while(!q.empty())
    {
        pii now = q.front();
        vis[now.F][now.S] = 1;
        RPT(i,4)
        {
            int nx = now.F + dx[i],
                ny = now.S + dy[i];
            if(tb[nx][ny] && !vis[nx][ny])
            {
                q.emplace(nx,ny);
                vis[nx][ny] = 1;
            }
        }
        q.pop();
    }
}

signed main()
{
    ShiYu;
    int t,h,w; cin >> t;
    while(t--)
    {
        cin >> h >> w;
        clear_arr(tb); clear_arr(vis);
        char x;
        RPT1(i,h) RPT1(j,w) 
        {
            cin >> x;
            tb[i][j] = (x == '.' ? 1 : 0);
        }
        // outputD(tb,h+1,w+1);
        int ans = 0;
        RPT1(i,h) RPT1(j,w)
        {
            if(tb[i][j] && !vis[i][j])
            {
                BFS(i,j);
                ++ans;
            }
        }
        cout << ans << '\n';
    }
}