#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f, mod = 1000000007;
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
void solve(){
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edge(m);
    DSU dsu(n);
    int ans = 0;
    int k = 0;
    for(int i = 0; i < m; i ++ ){
        int p, u, v, w;
        cin >> p >> u >> v >> w;
        u --, v --;
        if(p == 1){
            dsu.merge(u, v);
            ans += w;
            edge[i] = {INF, 1, 1};
        }else{
            edge[i] = {w, u, v};
        }
    }
    sort(edge.begin(), edge.end());
    for(auto [w, u, v]: edge){
        if(dsu.merge(u, v)) ans += w;
    }
    cout << ans << endl;
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