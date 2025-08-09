#include<bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define ll long long
#define ull unsigned ll
#define int ll
#define pii pair<int,int>
#define vii vector<pii>
#define pq priority_queue
#define pq_min priority_queue<int,vector<int>,greater<int>> 
#define F first
#define S second
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SZ(x) ((ll)x.size())
#define all(x) x.begin(), x.end()
#define MMn maxn = INT_MIN, minn = INT_MAX
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define remax(a, b) a = (a > b ? a : b)
#define remin(a, b) a = (a < b ? a : b)
#define coutE(x) cout << x << "\n"
#define coutS(x) cout << x << ' '
#define dbg(x) cerr << #x << "=" << x << "\n";
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define inputn(x,n) RPT(i,n) cin >> x[i] 
#define inputD(x,a,b) RPT(i,a) RPT(j,b) cin >> x[i][j]
#define output(x) for(auto i : x) dbg(i)
#define YN(x) cout << (x ? "YES" : "NO") << "\n"
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define yn(x) cout << (x ? "yes" : "no") << "\n"
#define SET(n) cout << fixed << setprecision(n)
#define nl(n) RPT(i,n) cout << "\n"
const double eps = 1e-8;
using namespace std;

//==========================================================================================

// 前綴和 AC
// 使 區間和 與 區間數 的比值最大化
// 因非嚴格遞減 所以區間永遠從 1 開始 不需枚舉所有區間

void solve()
{
    int n,a,b; cin >> n >> a >> b;
    vector<int> v(n),p(n+1); input(v);
    p[0] = 0;
    FOR(i,1,n+1) p[i] = p[i-1] + v[i-1];
    double maxn = INT_MIN;
    int j;
    FOR(i,1,n+1)
    {
        double val = (double)(p[i]) / (2*a+i*b);
        if(val > maxn)
        {
            maxn = val;
            j = i;
        }
    }
    cout << 1 << " " << j << "\n";
}

signed main(void)
{
    ShiYu;
    int t = 1; // cin >> t;
    while(t--) solve();
}