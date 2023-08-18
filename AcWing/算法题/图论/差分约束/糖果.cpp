#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 300010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int h[N], e[N], w[N], ne[N], idx;
int dist[N], cnt[N];
bool st[N];
int n, k;
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
bool spfa(){
    memset(dist, -0x3f, sizeof dist);
    dist[0] = 0;
    stack<int> q;
    q.push(0);
    st[0] = true;
    while(q.size()){
        auto t = q.top();
        q.pop();
        st[t] = false;

        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] < dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n + 1) return false;
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return true;
}
void solve(){
    cin >> n >> k;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i ++ ) {
        add(0, i, 1);
    }
    while(k --){
        int x, a, b;
        cin >> x >> a >> b;
        if(x == 1){
            add(a, b, 0), add(b, a, 0);
        }else if(x == 2){
            add(a, b, 1);
        }else if(x == 3){
            add(b, a, 0);
        }else if(x == 4){
            add(b, a, 1);
        }else{
            add(a, b, 0);
        }
    }
    if(!spfa()) cout << -1 << endl;
    else {
        int ans = 0;
        for(int i = 1; i <= n; i ++ ) ans += dist[i];
        cout << ans << endl;
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