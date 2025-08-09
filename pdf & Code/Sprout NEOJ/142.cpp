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
#define FOR1(i,a,b) for(int i=a+1; i<=b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; nl
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define clear_arr(x) memset(x,0,sizeof(x))

// DP
// 狀態 dp[i] = 取第 i 數時的最大值
// 轉移 分 3 段
// 1. [1,k] : dp[i] = arr[i];
// 2. [k+1,2k] : dp[i] = arr[i] + max[1,k]
// 3. [2k+1,n] : dp[i] = dp[j] + max[k+1,2k]

const int SP = 1e4;
int arr[SP], dp[SP], n, k, ans;

void process()
{
    clear_arr(arr); clear_arr(dp);
    RPT1(i,n) cin >> arr[i];
    RPT1(i,k) dp[i] = arr[i];   // 1
    FOR1(i,k,2*k) RPT1(j,i-k)   // 2
    {
        dp[i] = max(dp[i], arr[i] + arr[j]);
    }
    FOR1(i,2*k,n) FOR(j,i-2*k,i-k+1)    // 3
    {
        dp[i] = max(dp[i], dp[j] + arr[i]);
    }
    ans = -1;
    RPT(i,n+1) ans = max(ans, dp[i]);
}

signed main()
{
    ShiYu;
    int t; cin >> t;
    while(t--)
    {
        cin >> n >> k;
        process();
        cout << ans << '\n';
    }
}