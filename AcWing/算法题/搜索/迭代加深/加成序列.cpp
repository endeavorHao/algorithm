#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 210, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int path[N];
int x;
bool dfs(int u, int depth){
    if(u == depth) return path[u - 1] == x;
    bool vis[N] = {false};
    for(int i = u - 1; i >= 0; i -- ){
        for(int j = i; j >= 0; j -- ){
            int s = path[i] + path[j];
            if(s > x || vis[s] || s <= path[u - 1]) continue;
            vis[s] = true;
            path[u] = s;
            if(dfs(u + 1, depth)) return true;
        }
    }
    return false;
}
void solve(){
    path[0] = 1;
    while(cin >> x, x){
        int depth = 1;
        while(!dfs(1, depth)) depth ++;
        for(int i = 0; i < depth; i ++ ) cout << path[i] << " \n"[i == depth - 1];
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