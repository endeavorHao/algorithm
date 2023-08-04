#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 998244353;
typedef pair<int, int> PII;

int n, m;
struct Node
{
    int l, r;
    int sum, add, price;
}tr[N * 4];

void pushup(int u)
{
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % mod;
}

void pushdown(int u)
{
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if(root.add)
    {
        left.sum = (left.sum + (left.r - left.l + 1) * root.add % mod) % mod;
        left.add = (left.add + root.add) % mod;
        right.sum = (right.sum + (right.r - right.l + 1) * root.add % mod ) % mod;
        right.add = (right.add + root.add) % mod;
        root.add = 0;
    }
}

void build(int u, int l, int r)
{
    if(l == r) tr[u] = {l, r, 0, 0};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int v)
{
    if(tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].add = (tr[u].add + v) % mod;
        tr[u].sum = (tr[u].sum + (tr[u].r - tr[u].l + 1) * v % mod) % mod;
    }
    else 
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u << 1, l, r, v);
        if(r > mid) modify(u << 1 | 1, l, r, v);
        pushup(u);
    }
}

int query(int u, int l, int r)
{
    
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
 
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    if(l <= mid) sum = query(u << 1, l, r) % mod;
    if(r > mid) sum = (sum + query(u << 1 | 1, l, r)) % mod;
    return sum;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
    build(1, 1, n);
    int op;
    int l, r;
	int sum = 0;
    for(int i = 1; i <= m; i ++ ){
        cin >> op >> l >> r;
        if(op == 1) cout << query(1, l, r) % mod << endl;
        else{
            int v;
            cin >> v;
			v %= mod;
            modify(1, l, r, v);
        }
    }
    return 0;
}