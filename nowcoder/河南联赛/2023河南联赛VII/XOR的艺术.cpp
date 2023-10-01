#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
struct node{
    int l, r;
    int sum;
    int lazy;
}tr[N * 4];
int n, m;
string s;
void pushup(int u){
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void pushdown(int u){
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if(root.lazy){
        left.lazy ^= 1;
        right.lazy ^= 1;
        left.sum = left.r - left.l + 1 - left.sum;
        right.sum = right.r - right.l + 1 - right.sum;
        root.lazy = 0;
    } 
}
void build(int u, int l, int r){
    if(l == r) tr[u] = {l, r, s[r] == '1', 0};
    else{
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
void modify(int u, int l, int r){
    if(l <= tr[u].l && r >= tr[u].r) {
        tr[u].lazy ^= 1;
        tr[u].sum = tr[u].r - tr[u].l + 1 - tr[u].sum;
    }else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u << 1, l, r);
        if(r > mid) modify(u << 1 | 1, l, r);
        pushup(u);
    }
}
int query(int u, int l, int r){
    if(l <= tr[u].l && r >= tr[u].r) return tr[u].sum;

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    if(l <= mid) sum += query(u << 1, l, r);
    if(r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}
void solve(){
    cin >> n >> m;
    cin >> s;
    s = " " + s;
    build(1, 1, n);
    while(m -- ){
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 0){
            modify(1, l, r);
        }else{
            cout << query(1, l, r) << endl;
        }
    }
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	// cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}