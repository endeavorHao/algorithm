#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int dist[N];
void solve(){
	cin >> n >> m;
	memset(dist, -1, sizeof dist);
	
	auto bfs = [&](int sx){
		queue<int> q;
		q.push(sx);
		dist[sx] = 0;
		while(q.size()){
			auto t = q.front();
			q.pop();
			if(t == m) return dist[t];
			if(t + 1 < N && dist[t + 1] == -1){
				dist[t + 1] = dist[t] + 1;
				q.push(t + 1);
			}
			if(t - 1 >= 0 && dist[t - 1] == -1){
				dist[t - 1] = dist[t] + 1;
				q.push(t - 1);
			}
			if(t * 2 < N && dist[t * 2] == -1){
				dist[t * 2] = dist[t] + 1;
				q.push(t * 2);
			}
		}
		return -1ll;
	};
	cout << bfs(n) << endl;
	
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