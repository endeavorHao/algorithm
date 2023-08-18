#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 300010, INF = 0x3f3f3f3f3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int h[N], e[N], w[N], ne[N], idx;
int dist[N], cnt[N];
bool st[N];
int n, m1, m2;
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++; 
}
int spfa(int x){
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    memset(cnt, 0, sizeof cnt);
    queue<int> q;
    for(int i = 1; i <= x; i ++ ){
        dist[i] = 0;
        q.push(i);
        st[i] = true;
    }
    while(q.size()){
        auto t = q.front();
        q.pop();
        st[t] = false;

        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n) return true;
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        } 
    }
    return false;
}
void solve(){
    cin >> n >> m1 >> m2;
    memset(h, -1, sizeof h);
    for(int i = 1; i < n; i ++ ){
        add(i + 1, i, 0);
    }
    while(m1 -- ){
        int a, b, c;
        cin >> a >> b >> c;
        if(a > b) swap(a, b);
        add(a, b, c);
    }
    while(m2 -- ){
        int a, b, c;
        cin >> a >> b >> c;
        if(a > b) swap(a, b);
        add(b, a, -c);
    }
    if(spfa(n)) cout << -1 << endl;
    else{
        spfa(1);
        if(dist[n] == INF) cout << -2 << endl;
        else cout << dist[n] << endl;
    }
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