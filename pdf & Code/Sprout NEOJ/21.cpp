#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define all(x) x.begin(),x.end()
#define int long long

// TLE

signed main()
{
    ShiYu
    list<int> track;
    int n; cin >> n;
    track.resize(n);
    iota(track.begin(), track.end(), 1);
    int m,t,x; cin >> m;
    while(m--)
    {
        cin >> t >> x;
        if(t) 
        {
            if(x > 1)
            {
            auto it = find(all(track), x);
            iter_swap(it, prev(it));
            }
        } else track.remove(x);
    }
    for(auto i:track) cout << i << " ";
    cout << "\n";
    return 0;
}