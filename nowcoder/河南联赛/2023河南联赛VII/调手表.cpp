#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2000010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, k;
    cin >> n >> k;
    vector<int> dist(n + 1, 1e18);
    auto bfs = [&]() -> void{
        queue<int> q;
        dist[0] = 0;
        q.push(0);
        while(q.size()){
            auto t = q.front();
            q.pop();

            int x = t + 1;
            if(dist[x % n] > dist[t] + 1) {
                dist[x % n] = dist[t] + 1;
                q.push(x % n);
            } 
            x = (t + k) % n;
            if(dist[x] > dist[t] + 1){
                dist[x] = dist[t] + 1;
                q.push(x);
            }
        }
    };
    bfs();
    int ans = 0;
    for(int i = 0; i < n; i ++ ) ans = max(ans, dist[i]);
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