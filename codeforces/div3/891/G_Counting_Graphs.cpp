#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 998244353;
typedef pair<int, int> PII;
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
int qmi(int a, int b, int p){
    int ans = 1;
    while(b){
        if(b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}
void solve(){
	int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edge(n - 1);
    for(int i = 0; i < n - 1; i ++ ){
        int u, v, w;
        cin >> u >> v >> w;
        u --, v --;
        edge[i] = {w, u, v};
    }
    sort(edge.begin(), edge.end());

    DSU dsu(n);
    int ans = 1;
    for(auto [w, u, v] : edge){
        int cnt = dsu.size(u) * dsu.size(v) - 1;
        ans = ans * qmi(m - w + 1, cnt, mod) % mod;
        dsu.merge(u, v);
    }
    cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}