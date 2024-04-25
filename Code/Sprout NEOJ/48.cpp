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

// BST

struct Node
{
    int val;
    Node * left;
    Node * right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node * BST(int * a, int * b, int n)
{
    if(!n) return NULL;
    Node * node = new Node(*a);
    int idx = 0;
    while(idx < n)
    {
        if(b[idx] == *a) break;
        idx++;
    }
    node -> left = BST(a+1, b, idx);
    node -> right = BST(a+idx+1, b+idx+1, n-idx-1);
    cout << node -> val << "\n";ㄢㄢ
    return node;
}

signed main()
{
    ShiYu
    int n; cin >> n;
    int a[2005], b[2005];
    RPT(i,n)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b+n);
    BST(a,b,n);
}