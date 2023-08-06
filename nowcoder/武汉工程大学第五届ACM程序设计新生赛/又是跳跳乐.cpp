#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 100010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int dist[N];
int a[N];
bool st[N];
vector<int> block[110];
int n;
int bfs(){
    priority_queue<PII, vector<PII>, greater<PII>> q;
    memset(dist, -1, sizeof dist);
    q.push({0, 1});
    dist[1] = 0;
    while(q.size()){
        auto t = q.top();
        q.pop();
        if(st[t.y]) continue;
        st[t.y] = true;
        if(t.y == n) return dist[n];
        if(dist[t.y + 1] == -1){
            dist[t.y + 1] = dist[t.y] + 1;
            q.push({dist[t.y + 1], t.y + 1});
        }
        for(auto u: block[a[t.y]]){
            if(dist[u] == -1){
                dist[u] = dist[t.y] + 1;
                q.push({dist[u], u});
            }
        }
        block[a[t.y]].clear();
    }
    return -1;
}
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i ++ ) cin >> a[i], block[a[i]].push_back(i);
    cout << bfs() << endl;
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