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

// 建圖 模擬 第二種相遇方式卡關 放棄

void solve()
{
    int ans = 0;
    int n,l,k; cin >> n >> l >> k;
    vector<vector<int>> tb(l,vector<int>(l,0));
    vector<pair<int,int>> xy,mv; // xy 每隻螞蟻目前位置, mv 每隻螞蟻每秒要走的 x y 變化量
    char d; int x,y;
    RPT(i,n)
    {
        cin >> d >> x >> y;
        // 紀錄每隻每秒要走的 x y 變化量
        if(d == 'U') mv.emplace_back(-1,0);
        else if(d == 'D') mv.emplace_back(1,0);
        else if(d == 'L') mv.emplace_back(0,-1);
        else mv.emplace_back(0,1);
        xy.emplace_back(x-1,y-1);
        // 螞蟻先站好
        tb[x-1][y-1]++;
    }
    RPT(i,l) 
    {
        RPT(j,l) cout << tb[i][j] << " ";
        nl(1);
    }
    nl(3);
    // RPT(i,n) cout << mv[i].F << " " << mv[i].S << "\n";

    // 每隻開始走
    RPT(i,n)
    {
        // 離開原本的位置
        tb[xy[i].F][xy[i].S]--;
        // 紀錄移動後新位置座標
        int tx = xy[i].F + mv[i].F,
            ty = xy[i].S + mv[i].S;
        // 判斷邊界 跑出去可以從另一邊
        if(tx == -1) tx = l-1;
        else if(tx == l) tx = 0;
        else if(ty == -1) ty = l-1;
        else if(ty == l) ty = 0;
        // 移動到新位置
        tb[tx][ty]++;
    }
    // 判斷相遇

    RPT(i,l) 
    {
        RPT(j,l) cout << tb[i][j] << " ";
        nl(1);
    }
    nl(2);

    // while(k--)
    // {
    // }
}

signed main(void)
{
	ShiYu;
	solve();
}