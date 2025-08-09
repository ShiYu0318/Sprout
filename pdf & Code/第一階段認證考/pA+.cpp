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


const int SP = 505, dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
char tb[SP][SP];
int n, m, q;// now = 0;
bool vis[SP][SP];
queue<pair<int,pii>> mq;
vector<pair<int,pii>> meow;

int BFS(int t, int x, int y)
{
    mq.emplace(MP(t,MP(x,y)));
    vis[x][y] = 1;
    while(!mq.empty())
    {
        auto np = mq.front();
        // 動態加入 meow, vis 會被打亂
        // if(now < q && np.F == meow[now].F)
        // {
        //     mq.emplace(meow[now]);
        //     now++;
        // }
        
        // 4 side
        RPT(i,4)
        {
            int nx = np.S.F + dx[i],
                ny = np.S.S + dy[i];
            if(tb[nx][ny] == '@') return np.F+1;
            if(tb[nx][ny] == '#') continue;
            if(!vis[nx][ny])
            {
                mq.emplace(MP(np.F+1,MP(nx,ny)));
                vis[nx][ny] = 1;
            }
        }
        mq.pop();
    }
    return -1;
}

void solve()
{
    // INPUT
    cin >> n >> m;
    int kx,ky;
    RPT(i,n) RPT(j,m) 
    {
        cin >> tb[i][j];
        if(tb[i][j] == 'K') 
        {
            kx = i;
            ky = j;
        }
    }
    // q+1 隻 meow 每隻都做一次 BFS 取 min
    cin >> q;
    meow.resize(q+1);
    RPT(i,q) cin >> meow[i].F >> meow[i].S.F >> meow[i].S.S;
    meow[q] = (MP(0,MP(kx,ky)));
    sort(all(meow));
    // for(auto i:meow) cout << i.F << i.S.F << i.S.S << '\n';
    int ans = INT_MAX, tmp;
    RPT(i,q+1)
    {
        memset(vis,0,sizeof(vis));
        tmp = BFS(meow[i].F, meow[i].S.F, meow[i].S.S);
        if(tmp != -1) ans = min(ans, tmp);
    }
    if(ans == INT_MAX) cout << "= =\"\n";
    else cout << ans << '\n';
    // cout << (ans == -1 ? "==\"" : ans) << '\n';
    // RPT(i,n) RPT(j,m) cout << tb[i][j] << " \n"[j==m-1];
    
}


signed main()
{
    ShiYu;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}