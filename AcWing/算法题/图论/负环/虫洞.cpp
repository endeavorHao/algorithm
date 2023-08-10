#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 20010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int h[N], e[N], ne[N], w[N], idx;
int n, m1, m2;
int dist[N], cnt[N];
bool st[N];
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++; 
}
bool spfa(){
    memset(dist, 0, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(st, false, sizeof st);
    queue<int> q;
    for(int i = 1; i <= n; i ++ ){
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
    idx = 0;
    while(m1 -- ){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    while(m2 -- ){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, -c);
    }
    if(spfa()) cout << "YES" << endl;
    else cout << "NO" << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}