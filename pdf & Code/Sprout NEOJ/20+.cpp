#include <bits/stdc++.h>
using namespace std;
// #define ShiYu ios_base::sync_with_stdio(0);
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

// link list TLE

struct node
{
    int data;
    node * next;
};

struct Queue
{
    node * head;
    node * tail;
} q;

map<int,int> m;

void ENQUEUE(int e) {
    // 查看 m 中是否有 e，如果沒有則視為無組別
    int group = (m.find(e) != m.end() ? m[e] : -1);

    // 創建一個新節點
    node * newNode = new node;
    newNode -> data = e;
    newNode -> next = NULL;

    // 如果隊伍為空，更新頭和尾
    if (!q.head) q.head = q.tail = newNode;
    else 
    {   // 如果有組別，查找隊伍中同組的最後一個人
        if (group != -1) 
        {
            node * current = q.head;
            node * last = NULL;
            while (current) 
            {
                if (m[current -> data] == group) last = current;
                current = current -> next;
            }

            if (last) 
            {   // 找到同組最後一個插入
                newNode -> next = last -> next;
                last -> next = newNode;
                // 如果最後一個人是當前尾，則更新尾
                if (last == q.tail) q.tail = newNode;
            } 
            else // 如果隊伍中沒同組的，插入隊伍最後
            {
                q.tail -> next = newNode;
                q.tail = newNode;
            }
        } 
        else // 如果無組別，插入隊伍最後
        {   
            q.tail -> next = newNode;
            q.tail = newNode;
        }
    }
}

void DEQUEUE() 
{   // 輸出、刪除、更新開頭
    cout << q.head -> data << "\n";
    node * temp = q.head;
    q.head = q.head -> next;
    delete temp;
}

signed main()
{
    // ShiYu
    q.head = q.tail = NULL;
    int c = 1, t; scanf("%lld",&t);
    while (t--)
    {
        cout << "Line #" << c++ << "\n";
        int n; scanf("%lld",&n);
        RPT(i,n)
        {
            int j, k; scanf("%lld",&k);
            while(k--)
            {
                scanf("%lld",&j);
                m[j] = i;
            }
        }

        int o; scanf("%lld",&o);
        while (o--)
        {
            char s[8]; scanf("%s",s);
            if (strcmp(s, "ENQUEUE") == 0)
            {
                int e; scanf("%lld",&e);
                ENQUEUE(e);
            }
            else DEQUEUE();
            // 輸出 Queue 中所有資料
            // node * current = q.head;
            // cout << "Queue: ";
            // while (current) 
            // {
            //     cout << current -> data << " ";
            //     current = current -> next;
            // }
            // cout << "\n";
        }
    }
}