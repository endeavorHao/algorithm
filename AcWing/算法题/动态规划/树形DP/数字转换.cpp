#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int h[N], e[N], ne[N], idx;
int sum[N];
bool st[N];
int n, ans;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
int dfs(int u){
    st[u] = true;
    int d1 = 0, d2 = 0;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            int d = dfs(j) + 1;
            if(d >= d1) d2 = d1, d1 = d;
            else if(d > d2) d2 = d;
        }
    }
    ans = max(ans, d1 + d2);
    return d1;
}
void solve(){
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i ++ )
        for(int j = 2; j <= n / i; j ++ )
           sum[i * j] += i; 
    for(int i = 2; i <= n; i ++ ){
        if(i > sum[i]) add(sum[i], i);
    }
    for(int i = 1; i <= n; i ++ ){
        if(!st[i]){
            dfs(i);
        }
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