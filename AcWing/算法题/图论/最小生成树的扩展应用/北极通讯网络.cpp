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
struct node{
    int u, v;
    double w;
    bool operator<(const node &t)const{
        return w < t.w;
    }
};
void solve(){
	int n, k;
    cin >> n >> k;
    vector<PII> p(n);
    for(int i = 0; i < n; i ++ ) cin >> p[i].x >> p[i].y;
    vector<node> e(n * n);
    
    auto get_dist = [&](int i, int j) -> double{
        int x1 = p[i].x, y1 = p[i].y;
        int x2 = p[j].x, y2 = p[j].y;
        int dx = x2 - x1, dy = y2 - y1;
        return sqrt(dx * dx + dy * dy);
    };

    for(int i = 0, t = 0; i < n; i ++ )
        for(int j = 0; j < n; j ++, t ++ ){
            double w = get_dist(i, j);
            e[t] = {i, j, w};
        }
    sort(e.begin(), e.end());
    DSU dsu(n);
    int cnt = n;
    double res = 0;
    for(auto [u, v, w] : e){
        if(cnt <= k) break;

        if(dsu.merge(u, v)){
            cnt --;
            res = w;
        } 
    }
    printf("%.2lf\n", res);
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