#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n;
    cin >> n;
    vector<int> w(n);
    for(auto &v: w) cin >> v;

    auto f = [&]() -> int{
        int cnt = 0;
        for(int i = 0; i + 1 < n; i ++ ){
            if(w[i + 1] != w[i] + 1) cnt ++;
        }
        return (cnt + 2) / 3;
    };
    auto dfs = [&](auto self, int depth, int max_depth) -> bool{
        if(depth + f() > max_depth) return false;
        if(f() == 0) return true; 

        vector<vector<int>> g(5, vector<int>(n));
        for(int len = 1; len <= n; len ++ ){
            for(int l = 0; l + len - 1 < n; l ++ ){
                int r = l + len - 1;
                for(int k = r + 1; k < n; k ++ ){
                    g[depth] = w;
                    int y = l;
                    for(int x = r + 1; x <= k; x ++, y ++ ) w[y] = g[depth][x];
                    for(int x = l; x <= r; x ++, y ++ ) w[y] = g[depth][x];
                    if(self(self, depth + 1, max_depth)) return true;
                    w = g[depth];
                }
            }
        }
        return false;
    };
    int max_depth = 0;
    while(max_depth < 5 && !dfs(dfs, 0, max_depth)) max_depth ++;
    
    if(max_depth == 5){
        cout << "5 or more" << endl;
    }else cout << max_depth << endl;
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