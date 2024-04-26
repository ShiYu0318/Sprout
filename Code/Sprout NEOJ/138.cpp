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
#define clear_arr(x) memset(x,0,sizeof(x))

// DP bottom-up
// 狀態 dp[i] = 長度為 i 走廊能排列的方法數
// 轉移 dp[i] = 4 * dp[i-2] - dp[i-4]

const int MOD = 1e6+7, SP = 1e5+5;
int dp[SP];

void init()
{
    clear_arr(dp);
    dp[0] = 1;
    dp[2] = 3;
    for(int i=4; i < SP; i += 2)
    {
        dp[i] = (4 * dp[i-2] - dp[i-4] + MOD) % MOD;    // 避免負數
    }
}

signed main()
{
    ShiYu;
    init();
    int t,x; cin >> t;
    while(t--)
    {
        cin >> x;
        cout << dp[x] << '\n';
    }
}