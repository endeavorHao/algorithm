#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<int, string> PIS;
int n, m;
int h[N], rh[N], ne[N], w[N], e[N], idx;
int dist[N];
bool st[N];
int cnt[N];
int S, T, K;
void add(int h[], int a, int b, int c){
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
void dijkstra(){
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, T});
	memset(dist, 0x3f, sizeof dist);
	dist[T] = 0;
	while(heap.size()){
		auto t = heap.top();
		heap.pop();

		if(st[t.y]) continue;
		st[t.y] = true;
		for(int i = rh[t.y]; ~i; i = ne[i]){
			int j = e[i];
			if(dist[j] > t.x + w[i]){
				dist[j] = t.x + w[i];
				heap.push({dist[j], j});
			}
		}
	}
}
int astar(){
	priority_queue<PIII, vector<PIII>, greater<PIII>> heap;
	heap.push({dist[S], {0, S}});
	while(heap.size()){
		auto t = heap.top();
		heap.pop();
		cnt[t.y.y] ++;
		if(cnt[T] == K) return t.y.x;

		for(int i = h[t.y.y]; ~i; i = ne[i]){
			int j = e[i];
			if(cnt[j] < K)
			    heap.push({dist[j] + t.y.x + w[i], {t.y.x + w[i], j}});
		}
	}
	return -1;
}
void solve(){
	cin >> n >> m;
	memset(h, -1, sizeof h);
	memset(rh, -1, sizeof rh);
	while(m -- ){
		int a, b, c;
		cin >> a >> b >> c;
		add(h, a, b, c), add(rh, b, a, c);
	}
	cin >> S >> T >> K;
	dijkstra();
	if(S == T) K ++;
	cout << astar() << endl;
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