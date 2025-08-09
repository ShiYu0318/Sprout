#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios::sync_with_stdio(0);cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define RPT(i,n) FOR(i,0,n)
#define all(x) x.begin(), x.end()
#define output(x) RPT(i,x.size()) cout << x[i] << ' ';cout << '\n'

const int N = 1e5+5;
int ans[N][N];
vector<int> lead;

int find(int x)
{
	return (lead[x] == x ? x : lead[x] = find(lead[x]));
}

void Union(int x,int y)
{
	int a = find(x); int b = find(y);
	if(a != b)
	{
		lead[b] = a;
	}
	else
	{
		if(lead[y] == y) lead[y] = a;
	}
}

signed main()
{
    ShiYu;
    int n,m; cin >> n >> m;
    lead.resize(n); iota(all(lead),1); output(lead);
    int a,b;
    RPT(i,m)
    {
        cin >> a >> b;
        Union(a,b);
    }
    int q; cin >> q;
    int a,b;
    while(q--)
    {
        cin >> a >> b;
        
    }
}