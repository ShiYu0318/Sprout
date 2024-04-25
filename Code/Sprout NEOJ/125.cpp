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

vi v,pf;
int ans, n;
const int MOD = 1e7+19;

void merge(int l, int r)
{
    int mid = (l+r)/2, tmp[r-l+1];
    pf[l] = 0;
    FOR(i,l,mid+1) pf[i+1] = pf[i] + v[i];
    for(int i=l, j=mid+1, k=0; i <= mid || j <= r; ++k)
    {
        if(j > r || (v[i] <= v[j] && i <= mid))
        {
            tmp[k] = v[i];
            ++i;
        }
        else
        {
            tmp[k] = v[j];
            int p = pf[mid+1] - pf[i] + v[j] * (mid - i + 1);
            ans += p; ans %= MOD;
            ++j;
        }
    }
    for(int i=l, j=0; i <= r; ++i, ++j) v[i] = tmp[j];
}

void MergeSort(int l, int r)
{
    if(l == r) return;
    int mid = (l+r)/2;
    MergeSort(l,mid); MergeSort(mid+1,r);
    merge(l,r);
}

signed main()
{
    ShiYu;
    cin >> n;
    v.resize(n); input(v);
    pf.resize(n+1); pf[0] = 0;
    MergeSort(0,n-1);
    cout << ans << '\n';
}