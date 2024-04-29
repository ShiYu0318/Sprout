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

const int SP = 1e5+5;
int n, m, arr[SP];

bool check(int x)
{
    int sum = 0, ans = 1;
    RPT(i,n)
    {
        if(arr[i] > x) return 0;
        sum += arr[i];
        if(sum + arr[i+1] > x)
        {
            sum = 0;
            ++ans;
        }
    }
    return (ans > m ? 0 : 1);
}

signed main()
{
    ShiYu;
    int t; cin >> t;
    while(t--)
    {
        cin >> n >> m;
        arr_clear(arr);
        RPT(i,n) cin >> arr[i];
        arr[n] = -INT_MAX;
        int l = 0, r = 1e9;
        while(r - l > 1)
        {
            int mid = (l+r)/2;
            if(check(mid)) r = mid;
            else l = mid;
        }
        cout << r << '\n';
    }
}