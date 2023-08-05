#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, m;
    cin >> n >> m;
    vector<bool> vis(n + 1, false);
    while(m -- ){
        int a, b;
        cin >> a >> b;
        vis[b] = true;
    }
    int t = -1;
    for(int i = 1; i <= n; i ++ ){
        if(!vis[i] && t != -1){
            t = -1;
            break;
        }else if(!vis[i]) t = i;
    }
    cout << t << endl;
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