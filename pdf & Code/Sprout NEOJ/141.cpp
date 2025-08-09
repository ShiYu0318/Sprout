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
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';

// DP bottom-up
// 狀態 dp[i] = 取第 i 個數字時的最大值
// 轉移 dp[i] = max(dp[i-2], dp[i-3]) + a[i] 不能取前一個

const int SP = 1e5+5;
int a[SP], dp[SP], n;

void process()
{
    dp[0] = a[0];
    dp[1] = a[1];
    dp[2] = a[0] + a[2];
    FOR(i,3,n+1)
    {
        dp[i] = max(dp[i-2], dp[i-3]) + a[i];
    }
}

signed main()
{
    ShiYu;
    int t; cin >> t;
    while(t--)
    {
        cin >> n;
        RPT(i,n) cin >> a[i];
        process();
        cout << max(dp[n], dp[n-1]) << '\n';
    }
}