#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int h[N], e[N], ne[N], idx;
int d[N];
int tt, ans[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
bool topsort(){
    queue<int> q;
    for(int i = 1; i <= n; i ++ ) if(d[i] == 0) q.push(i);
    
    while(q.size()){
        auto t = q.front();
        q.pop();
        ans[ ++ tt] = t;
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(-- d[j] == 0) q.push(j);
        }
    }
    return tt == n;
}
void solve(){
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while(m -- ){
	    int a, b;
	    cin >> a >> b;
	    add(a, b);
	    d[b] ++;
	}
	if(topsort()){
	    for(int i = 1; i <= tt; i ++ ) cout << ans[i] << ' ';
	    cout << endl;
	}else{
	    cout << -1 << endl;
	}
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