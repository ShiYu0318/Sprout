#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define output(x) for(auto i : x) cout << i << " "
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

int group[1000005], group_cnt[1005];
list<int> line;
list<int>::iterator group_tail[1005];

void ENQUEUE()
{
    int cur; cin >> cur;
    int cur_group = group[cur];
    if(cur_group > 0)
    {
        if(group_cnt[cur_group] == 0)
        {
            line.push_back(cur);
            group_tail[cur_group] = --line.end();
        }
        else group_tail[cur_group] = line.insert(++group_tail[cur_group],cur);
        group_cnt[cur_group]++;
    }
    else line.push_back(cur);
}

void DEQUEUE()
{
    int head = line.front();
    if(group[head] > 0) group_cnt[group[head]]--;
    cout << line.front() << "\n";
    line.pop_front();
}

signed main()
{
    ShiYu
    int t; cin >> t;
    RPT(c,t)
    {
        cout << "Line #" << c+1 << "\n";
        memset(group, 0, sizeof(group));
        memset(group_cnt, 0, sizeof(group_cnt));
        int n; cin >> n;
        RPT(i,n)
        {
            int k; cin >> k;
            RPT(j,k)
            {
                int temp; cin >> temp;
                group[temp] = i+1;
            }
        }

        int q; cin >> q;
        while(q--)
        {
            string s; cin >> s;
            if(s == "ENQUEUE") ENQUEUE();
            else DEQUEUE();
        }
        line.clear();
        fill(group_tail, group_tail + 1005, line.end());
    }
}