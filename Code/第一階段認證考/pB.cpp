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

void solve()
{
    int q,k; cin >> q >> k;
    int o,x,y,p=0;
    multiset<int> ms;
    while(q--)
    {
        cin >> o;
        if(o == 1)
        {
            cin >> x;
            ms.insert(x-p);
        }
        else if(o == 2)
        {
            cin >> y;
            p += y;
        }
        else
        {
            if(ms.size() < k) cout << "No solution\n";
            else
            {
                // cout << *(ms.begin()+k)+p << '\n';
                // for(auto i:ms) cout << i << ' ';
                auto it = ms.begin();
                RPT(i,k-1) it++;
                cout << *it + p << '\n';
            }
        }
    }
}


signed main()
{
    ShiYu;
    int t = 1;
    //cin >> t;
    while(t--) solve();
}