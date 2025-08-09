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
#define arr_clear(x) memset(x, 0, sizeof(x))

// +++

const int SP = 1e6+5;

signed main()
{
    ShiYu;
    int t; cin >> t;
    while(t--)
    {
        int n, ans = 0, cnt[SP]; 
        arr_clear(cnt); vi v;
        cin >> n;
        while(n--)
        {
            int k, end = v.size(); cin >> k;
            while(!v.empty() && v.back() < k)
            {
                cnt[end--] = 0;
                v.pop_back();
                ans++;
            }
            if(v.empty()) v.EB(k);
            else
            {
                if(v.back() == k && end > 1)
                {
                    cnt[end + 1] += cnt[end] + 1;
                    ans += cnt[end+1];
                }
                v.EB(k); ++ans;
            }
        }
        cout << ans << '\n';
    }
}