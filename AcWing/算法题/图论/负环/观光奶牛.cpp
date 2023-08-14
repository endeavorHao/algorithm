#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 20010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int wf[N];
int h[N], e[N], ne[N], wt[N], idx; 
double dist[N];
int cnt[N];
bool st[N];
int n, m;
void add(int a, int b, int c){
    e[idx] = b, wt[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
bool spfa(double mid){
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);
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
            // 这里是求是否存在正环
            if(dist[j] < dist[t] + wf[t] - mid * wt[i]){
                dist[j] = dist[t] + wf[t] - mid * wt[i];
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
	cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i ++ ) cin >> wf[i];
    while(m -- ){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    double l = 0, r = 1000;
    while(r - l > 1e-4){
        double mid = (l + r) / 2;
        if(spfa(mid)) l = mid;
        else r = mid;
    }
    printf("%.2lf\n", r);
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