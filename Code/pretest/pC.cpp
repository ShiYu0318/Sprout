#include<bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0);cin.tie(0)
#define ll long long
#define ull unsigned ll
#define int ll
#define pii pair< int, int >
#define vii vector< pii >
#define pq priority_queue
#define pq_min priority_queue < int, vector<int>, greater<int> > 
#define F first
#define S second
#define eb emplace_back
#define mp(a,b) make_pair(a,b)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(), x.end()
#define MMn maxn = INT_MIN, minn = INT_MAX
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define remax(a, b) a = (a > b ? a : b)
#define remin(a, b) a = (a < b ? a : b)
#define coutE(x) cout << x << "\n"
#define coutS(x) cout << x << ' '
#define dbg(x) cerr << #x << "=" << x << "\n";
#define RPT(i,n) for(int i=0;i<n;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define input(x) for(auto &i : x) cin >> i
#define inputn(x,n) RPT(i,n) cin >> x[i] 
#define inputD(x,a,b) RPT(i,a) RPT(j,b) cin >> x[i][j]
#define output(x) for(auto &i : x) dbg(i)
#define YN(x) cout << (x ? "YES" : "NO") << "\n"
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define yn(x) cout << (x ? "yes" : "no") << "\n"
#define SET(n) cout << fixed << setprecision(n)
#define nl(n) RPT(i,n) cout << "\n"
const double eps = 1e-8;
using namespace std;

//==========================================================================================

// Score:50 substr TLE

bool check(string s)
{
    int ss = s.size();
    /*
    規則：
    從後面看回來
    一次都看一個音節
    不符合規則的直接 return false
    有三種狀況
        如果音節最後面是 n 
            代表這是第二種音節
            只需要把 nn nm 判掉就好 注意邊界
            n 前面兩個字母是第一種音節 可以丟給下一個看
            注意如果剩下最前面那字是 n 也不合法
        如果音節最後面是母音
            代表這是第一種音節
            前面會有 1 個子音 所以 i-1 為母音不合法
            特判 ji, wu, wo, ti 注意邊界
        如果音節最後面是不包含 n 的子音 回傳否
    */
    for(int i=ss-1;i>=0;--i)
    {
        if(s[i] == 'n')
        {
            if(i == 0 || (i != ss-1 && (s[i+1] == 'n' ||  s[i+1] == 'm'))) return false;
        }
        else if((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u'))
        {
            if(i != 0)
            {
                if((s[i-1] == 'a') || (s[i-1] == 'e') || (s[i-1] == 'i') || (s[i-1] == 'o') || (s[i-1] == 'u'))
                {
                    return false;
                }
                else if((s[i-1] == 'j' && s[i] == 'i') || 
                        (s[i-1] == 'w' && s[i] == 'u') || 
                        (s[i-1] == 'w' && s[i] == 'o') || 
                        (s[i-1] == 't' && s[i] == 'i')) return false;
            }
            i--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    bool find = false;
    string s; cin >> s;
    int ss = s.size();
    // 從最長字串開始找
    for(int i=ss;i>0;--i)
    {
        vector<string> v;
        // 長度為 i 的子字串有幾個
        int n = ss - i + 1;
        for(int j=0;j<n;++j)
        {
            string ts = s.substr(j,i);
            //cout << check(ts) << " " << ts << "\n";
            if(check(ts))
            {
                v.emplace_back(ts);
            }
        }
        if(!v.empty())
        {
            sort(all(v));
            cout << v[0] << "\n";
            find = true;
            break;
        }
        // nl(2);
    }
    if(!find) cout << -1 << "\n";
}

signed main(void)
{
	ShiYu;
	solve();
}