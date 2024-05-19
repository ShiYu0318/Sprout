#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define RPT(i,n) for(int i=0;i<n;++i)
#define mid ((l + r) >> 1)
#define ls (x << 1)
#define rs ((x << 1) | 1)

// RMQ

const int MAXN = 2e6+5;
int seg[MAXN << 2], arr[MAXN], n;

void pull(int x)
{
    seg[x] = min(seg[ls],seg[rs]);
}

void build(int x, int l ,int r)
{
    if(l == r) seg[x] = arr[l];
    else
    {
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pull(x);
    }
}

void modify(int x, int l, int r, int pos, int val)
{
    if (pos < l || r < pos) return;
    if (l == r) seg[x] = val;
    else
    {
        modify(ls, l, mid, pos, val);
        modify(rs, mid + 1, r, pos, val);
        pull(x);
    }
}

int query(int x, int l, int r, int ql, int qr)
{
    if(qr < l || r < ql) return INT_MAX;
    if(ql <= l && r <= qr) return seg[x];
    int lq = query(ls, l, mid, ql, qr);
    int rq = query(rs, mid + 1, r, ql, qr);
    return min(lq, rq);
}

signed main()
{
    ShiYu;
    int n,q; cin >> q >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    build(1,0,n-1);
    int t,a,b;
    while(q--)
    {
        cin >> t >> a >> b;
        if(t == 1) cout << query(1,0,n-1,a,b) << '\n';
        else modify(1,0,n-1,a,b);
    }
}