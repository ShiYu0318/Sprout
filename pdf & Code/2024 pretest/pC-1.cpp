#include<bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define ll long long
#define ull unsigned ll
#define int ll
#define pii pair<int,int>
#define vii vector<pii>
#define pq priority_queue
#define pq_min priority_queue<int,vector<int>,greater<int>> 
#define F first
#define S second
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SZ(x) ((ll)x.size())
#define all(x) x.begin(), x.end()
#define MMn maxn = INT_MIN, minn = INT_MAX
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define remax(a, b) a = (a > b ? a : b)
#define remin(a, b) a = (a < b ? a : b)
#define coutE(x) cout << x << "\n"
#define coutS(x) cout << x << ' '
#define dbg(x) cerr << #x << "=" << x << "\n";
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define inputn(x,n) RPT(i,n) cin >> x[i] 
#define inputD(x,a,b) RPT(i,a) RPT(j,b) cin >> x[i][j]
#define output(x) for(auto i : x) dbg(i)
#define YN(x) cout << (x ? "YES" : "NO") << "\n"
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define yn(x) cout << (x ? "yes" : "no") << "\n"
#define islower(x) ((x) >= 'a' && (x) <= 'z')
#define isupper(x) ((x) >= 'A' && (x) <= 'Z')
#define isletter(x) (islower(x) || isupper(x))
#define SET(n) cout << fixed << setprecision(n)
#define nl(n) RPT(i,n) cout << "\n"
const double eps = 1e-8;
using namespace std;

//==========================================================================================

// AC

// 將 s 開成全域 直接用 index 去檢查 減少原版 substr 搬動浪費的操作

string s;

bool isvowel(char c)
{
    return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
}

bool check(int x, int y)
{
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
    for(int i=y;i>=x;--i)
    {
        if(s[i] == 'n')
        {
            if(i == x || (i != y && (s[i+1] == 'n' ||  s[i+1] == 'm'))) return false;
        }
        else if(isvowel(s[i]))
        {
            if(i != x)
            {
                if(isvowel(s[i-1])) return false;
                else if((s[i-1] == 'j' && s[i] == 'i') || 
                        (s[i-1] == 'w' && s[i] == 'u') || 
                        (s[i-1] == 'w' && s[i] == 'o') || 
                        (s[i-1] == 't' && s[i] == 'i')) return false;
            }
            i--;
        }
        else return false;
    }
    return true;
}

bool cmp(pii a, pii b)
{
    for(int i=a.F,j=b.F,F;i<=a.S;++i,++j)
    {
        if(s[i] > s[j]) return true;
        else if(s[i] < s[j]) return false;
    }
}

void solve()
{
    bool find = false;
    cin >> s;
    int ss = s.size();
    for(int i=ss;i>0;--i)   // 從最長字串開始找
    {
        pii ms={-1,-1};
        int n = ss - i + 1; // 長度為 i 的子字串有幾個
        for(int j=0;j<n;++j)
        {
            if(check(j,i+j-1)) 
            {
                pii pass = {j,i+j-1};
                if(ms.F == -1 && ms.S == -1 || cmp(ms,pass)) ms = pass;
            }
        }
        if(ms.F != -1 && ms.S != -1)
        {
            for(int i=ms.F;i<=ms.S;++i) cout << s[i];
            cout << "\n";
            find = true;
            break;
        }
    }
    if(!find) cout << -1 << "\n";
}

signed main(void)
{
	ShiYu;
	solve();
}