#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,x) for(int i=a;i<x;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)

struct node
{
    int id;
    node *next, *prev;
    node() : next(nullptr), prev(nullptr) {}
};

node *player[100005];
int n;

void Delete(int x)
{
    player[x] -> prev -> next = player[x] -> next;
    player[x] -> next -> prev = player[x] -> prev;
}

void Swap(int x) {
    node* pp = player[x] -> prev -> prev;
    if (!pp) return;
    node* p = player[x] -> prev;
    node* n = player[x] -> next;
    pp -> next = player[x];
    player[x] -> prev = pp;
    player[x] -> next = p;
    p -> next = n;
    n -> prev = p;
    p -> prev = player[x];
}

void output()
{
    stack<int> s;
    int cur = n+1;
    while(player[cur] -> prev != nullptr)
    {
        if(cur != n+1) s.push(player[cur] -> id);
        cur = player[cur] -> prev -> id;
    }
    while(s.size() > 1)
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout<< s.top() << "\n";
}

signed main()
{
    ShiYu
    int m; cin >> n >> m;
    RPT(i,n+3)
    {
        player[i] = new node();
        player[i] -> id = i;
    }
    FOR(i,1,n+3)
    {
        player[i] -> prev = player[i-1];
        player[i] -> next = player[i+1];
    }
    RPT(i,m)
    {
        int t,x; cin >> t >> x;
        if(t) Swap(x); 
        else Delete(x);
    }
    output();
}