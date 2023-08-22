#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 20010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int h[N], e[N], w[N], ne[N], idx;
int n;
int dp[N][3];
bool st[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}   
// dp[i][0] 表示i不放但在父节点放
// dp[i][1] 表示i不放但在子节点放
// dp[i][0] 表示i放

void dfs(int u){
    dp[u][2] = w[u];
    int sum = 0;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        dfs(j);
        dp[u][0] += min(dp[j][1], dp[j][2]);
        dp[u][2] += min({dp[j][0], dp[j][1], dp[j][2]});
        sum += min(dp[j][1], dp[j][2]);
    }
    dp[u][1] = 1e9;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        dp[u][1] = min(dp[u][1], dp[j][2] + sum - min(dp[j][1], dp[j][2]));
    }
}
void solve(){
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 0; i < n; i ++ ) {
        int id, cnt;
        cin >> id >> w[id] >> cnt;
        while(cnt -- ){
            int x;
            cin >> x;
            add(id, x);
            st[x] = true;
        }
    }
    int root = 1;
    while(st[root]) root ++;
    dfs(root);
    cout << min(dp[root][1], dp[root][2]) << endl;
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