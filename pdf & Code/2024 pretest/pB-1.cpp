#include<bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0);cin.tie(0)
#define ll long long
#define ull unsigned ll
#define int ll
#define pii pair< int, int >
#define vii vector< pii >
#define pq priority_queue
#define pq_min priority_queue < int, vector<int>, greater<int> > 
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(), x.end()
#define MMn maxn = INT_MIN, minn = INT_MAX
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define remax(a, b) a = (a > b ? a : b)
#define remin(a, b) a = (a < b ? a : b)
#define coutE(x) cout << x << "\n"
#define coutS(x) cout << x << ' '
#define dbg(x) cerr << #x << "=" << x << "\n";
#define RPT(i,n) for(int i=0;i<n;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define input(x) for(auto &i : x) cin >> i
#define inputD(x) for(auto &i : x) for(auto &j : i) cin >> j;
#define inputn(x,n) RPT(i,n) cin >> x[i] 
#define output(x) for(auto &i : x) dbg(i)
#define YN(x) cout << (x ? "YES" : "NO") << "\n"
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define yn(x) cout << (x ? "yes" : "no") << "\n"
#define SET(n) cout << fixed << setprecision(n)
#define nl(n) RPT(i,n) cout << "\n"
const double eps = 1e-8;
using namespace std;

//==========================================================================================

// Score:55 queue TLE

void solve()
{
    int ans = 0;
    int n,l,k; cin >> n >> l >> k;
    vii mv(n); // 每隻螞蟻每秒要走的 x y 變化量
    vector<queue<pair<int,int>>> xy(n); // queue 維持兩個元素紀錄每隻螞蟻前個座標與目前座標 
    char d; int x,y;
    RPT(i,n)
    {
        cin >> d >> x >> y;
        // 紀錄每隻每秒要走的 x y 變化量
        if(d == 'U') mv[i] = make_pair(-1,0);
        else if(d == 'D') mv[i] = make_pair(1,0);
        else if(d == 'L') mv[i] = make_pair(0,-1);
        else mv[i] = make_pair(0,1);
        // 每隻的座標放進 queue
        xy[i].emplace(x-1,y-1);
    }


    RPT(q,k)
    {
        // 每隻螞蟻開始走
        RPT(i,n)
        {
            // 紀錄移動後新座標
            int tx = xy[i].back().F + mv[i].F,
                ty = xy[i].back().S + mv[i].S;
            // 判斷邊界 跑出去可以改成從另一邊進來
            if(tx == -1) tx = l-1;
            else if(tx == l) tx = 0;
            else if(ty == -1) ty = l-1;
            else if(ty == l) ty = 0;

            // 每次有新座標就把上上次的座標pop掉 我們只需要前個座標與目前座標
            if(xy[i].front() != xy[i].back()) xy[i].pop();
            xy[i].emplace(tx,ty);
        }

        RPT(i,n)
        {
            FOR(j,1,n-i)
            {
                // 判斷相遇 1. 兩隻螞蟻現在位置一樣 or 2. (A 螞蟻現在位置 = B 螞蟻前個位置) 且 (B 螞蟻現在位置 =  A 螞蟻前個位置)
                if((xy[i].back() == xy[i+j].back()) || (xy[i].back() == xy[i+j].front()) && (xy[i+j].back() == xy[i].front()))
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
}

signed main(void)
{
	ShiYu;
	solve();
}