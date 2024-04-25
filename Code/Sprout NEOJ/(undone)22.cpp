#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << " "
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

// 

signed main()
{
    ShiYu
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> v(n),a,b; input(v);
        FOR(i,0,n)
        {
            bool find = false;
            FOR(j,i+1,n)
            {
                if(v[j] > v[i])
                {
                    a.emplace_back(j);
                    find = true;
                    break;
                }
            }
            if(!find) a.emplace_back(-1);
            if(i == 0)
            {
                b.emplace_back(-1);
                continue;
            }
            find = false;
            rFOR(j,i)
            {
                if(v[j] > v[i])
                {
                    b.emplace_back(j);
                    find = true;
                    break;
                }
            }
            if(!find) b.emplace_back(-1);
        }
        // output(a);cout << "\n";output(b);cout << "\n";

        int ans = n-1;
        
        FOR(i,0,n-2)
        {
            FOR(j,i+2,n)
            {
                // cout << "\n";
                // cout << "i:" << i << " j:" << j;
                if(!(i < a[i] && a[i] < j))
                {
                    if(!(i < b[j] && b[j] < j)) ++ans;
                    // cout << " ans:" << ans << "\n";
                } else break;
            }
        }
        cout << ans << "\n";
    }
}
