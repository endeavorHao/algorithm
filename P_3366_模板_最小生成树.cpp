    #include <bits/stdc++.h>
    #define x first
    #define y second
    #define int long long
    #define endl "\n"
    #define all(v) v.begin(), v.end()
    using namespace std;
    const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
    typedef pair<int, int> PII;
    typedef pair<int, PII> PIII;
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
        vector<array<int, 3>> e(m);
        for(int i = 0; i < m; i ++ ) {
            int u, v, w;
            cin >> u >> v >> w;
            u --, v --;
            e[i] = {w, u, v};
        }
        sort(all(e));
        DSU dsu(n);
        int sum = 0, cnt = 0;
        for(auto [w, u, v]: e){
            if(dsu.merge(u, v)){
                sum += w;
                cnt ++;
            }
        }
        if(cnt != n - 1) cout << "orz" << endl;
        else{
            cout << sum << endl;
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