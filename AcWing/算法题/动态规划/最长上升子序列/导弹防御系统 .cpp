#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
int up[N], down[N];
int ans;
void dfs(int u, int su, int sd){
    if(su + sd >= ans) return ;
    if(u == n){
        ans = su + sd;
        return ;
    }
    
    int k = 0;
    while(k < su && a[u] >= up[k]) k ++;
    int t = up[k];
    up[k] = a[u];
    if(k == su) dfs(u + 1, su + 1, sd);
    else dfs(u + 1, su, sd);
    up[k] = t;

    k = 0;
    while(k < sd && a[u] <= down[k]) k ++;
    t = down[k];
    down[k] = a[u];
    if(k == sd) dfs(u + 1, su, sd + 1);
    else dfs(u + 1, su, sd);
    down[k] = t;
}
void solve(){
	while(cin >> n, n){
        for(int i = 0; i < n; i ++ ) cin >> a[i];
        ans = INF;
        dfs(0, 0, 0);
        cout << ans << endl;
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