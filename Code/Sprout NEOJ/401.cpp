#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define x first
#define y second
#define EB emplace_back
#define endl '\n'
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

struct Pt
{
    int x,y;
    Pt operator - (Pt b) {return {x - b.x, y - b.y};}
    int operator * (Pt b) {return x * b.x + y * b.y;}
    int operator ^ (Pt b) {return x * b.y - y * b.x;}
};

vector<Pt> v;

int cross(Pt o, Pt a, Pt b)
{
    int t = (a - o) ^ (b - o);
    if(t < 0) return -1;
    return (t > 0);
}

signed main()
{
    ShiYu;
    int n; cin >> n;
    while(n--)
    {
        Pt p[4];
        RPT(i,4) cin >> p[i].x >> p[i].y;
        int a = cross(p[0],p[1],p[2]),
            b = cross(p[0],p[1],p[3]),
            c = cross(p[2],p[3],p[0]),
            d = cross(p[2],p[3],p[1]);
        Yn(a * b <= 0 && c * d <= 0 || a == 0 && b == 0);
    }
}