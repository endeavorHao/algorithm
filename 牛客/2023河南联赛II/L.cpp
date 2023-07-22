#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 100010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
char str[N];
struct node{
    int l, r;
    int llen, lch, rlen, rch;
    int mlen, mch, mpos;
}tr[N << 2];
void pushup(node &u, node &l, node &r){
    u.l = l.l, u.r = r.r;
    u.llen = l.llen, u.lch = l.lch;
    if(l.r - l.l + 1 == l.llen && r.lch == l.rch){
        u.llen = l.llen + r.llen;
    }
    u.rlen = r.rlen, u.rch = r.rch;
    if(r.r - r.l + 1 == r.rlen && r.lch == l.rch){
        u.rlen = l.rlen + r.rlen;
    }
    if(l.mpos + l.mlen - 1 <= l.r){
        u.mlen = l.mlen, u.mch = l.mch, u.mpos = l.mpos; 
    }
    if(l.mpos + l.mlen - 1 == l.r && l.mch == r.lch){
        u.mlen = l.mlen + r.llen, u.mch = l.mch, u.mpos = l.mpos;
    }
    if(r.lch == l.rch && l.rlen + r.llen > u.mlen){
        u.mlen = l.rlen + r.llen, u.mch = l.rch, u.mpos = l.r - l.rlen + 1;

    }
    if(r.mlen > u.mlen){
        u.mlen = r.mlen, u.mch = r.mch, u.mpos = r.mpos;
    }
}
void pushup(int u){
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}
void build(int u, int l, int r){
    if(l == r) tr[u] = {l ,l, 1, str[l] - 'a', 1, str[l] - 'a', 1, str[l] - 'a', l};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
void modify(int u, int pos, int v){
    if(tr[u].l == tr[u].r && tr[u].l == pos) tr[u] = {pos ,pos, 1, v, 1, v, 1, v, pos};
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(pos <= mid) modify(u << 1, pos, v);
        else modify(u << 1 | 1, pos, v);
        pushup(u);
    }
}
node query(int u, int l, int r){
    // cout << tr[u].l << ' ' << tr[u].r << endl;
    if(tr[u].l >= l && tr[u].r <= r) return tr[u];
    int mid = tr[u].l + tr[u].r >> 1;
    if(r <= mid) return query(u << 1, l, r);
    else if(l > mid) return query(u << 1 | 1, l, r);
    else{
        auto left = query(u << 1, l, r);
        auto right = query(u << 1 | 1, l, r);
        node ans;
        pushup(ans, left, right);
        return ans;
    }
}
void solve(){
	cin >> n >> m;
    cin >> str + 1;
    build(1, 1, n);
    while(m -- ){
        int op;
        cin >> op;
        if(op == 1){
            int l, r;
            cin >> l >> r;
            auto ans = query(1, l, r);
            cout << ans.mpos << ' ' << ans.mpos + ans.mlen - 1 << endl;
        }else if (op == 2){
            int pos;
            char x;
            cin >> pos >> x;
            modify(1, pos, x - 'a');
        }
    }
}
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
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