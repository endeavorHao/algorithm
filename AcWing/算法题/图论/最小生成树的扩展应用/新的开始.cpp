#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int w[N], g[N][N];
int dist[N];
bool st[N];
int n;
int prim(){
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    int res = 0;
    for(int i = 0; i < n + 1; i ++ ){
        int t = -1;
        for(int j = 0; j <= n; j ++ )
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        
        res += dist[t];
        st[t] = true;

        for(int j = 0; j <= n; j ++ )
            dist[j] = min(dist[j], g[t][j]);
    } 
    return res;
}
void solve(){
	cin >> n;
    for(int i = 1; i <= n; i ++ ){
        int x;
        cin >> x;
        g[0][i] = x;
    }
    for(int i = 1; i <= n; i ++ )
        for(int j = 1; j <= n; j ++ )
            cin >> g[i][j]; 
    cout << prim() << endl;
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