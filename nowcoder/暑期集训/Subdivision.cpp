#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 400010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m, k;
int h[N], e[N], ne[N], idx;
int dist[N];
bool st[N];
int ans;
void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void bfs(){
	queue<PII> q;
	q.push({1, -1});
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
    int sum = 0;
	while(q.size()){	
		auto t = q.front();
		q.pop();
        if(dist[t.x] <= k) ans ++;

        int cnt = 0;
		for(int i = h[t.x]; ~i; i = ne[i], cnt ++){
            int j = e[i];
            if(j == t.y) continue;
            if(dist[j] == dist[t.x] + 1){ 
                if(dist[t.x] <= k)
				    ans += k - dist[t.x];
                if(dist[j] <= k)
				    ans += k - dist[j];
            }else if(dist[j] == dist[t.x]){
                if(dist[t.x] <= k)
				    sum += k - dist[t.x];
                if(dist[j] <= k)
				    sum += k - dist[j];
            }
            else if(dist[j] > dist[t.x] + 1){ 	
				dist[j] = dist[t.x] + 1;
				q.push({j, t.x});
			}
		}
        if(cnt == 1 && dist[t.x] <= k && t.x != 1) ans += k - dist[t.x];
	}
    ans = ans + sum / 2;
}

void sovle(){
	cin >> n >> m >> k;
    memset(h, -1, sizeof h);
	while(m --){
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	bfs();
	cout << ans << endl;
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
	//cin >> T;
	while(T -- ){
		sovle();
	}
	return 0;
}