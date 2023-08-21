#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int h[N], e[N], ne[N], idx;
int d[N], cnt;
int ans[N];
int n;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void topsort(){
    queue<int> q;
    for(int i = 1; i <= n; i ++ ){
        if(!d[i]) q.push(i);
    }
    while(q.size()){
        auto t = q.front();
        q.pop();
        ans[cnt ++ ] = t;

        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(-- d[j] == 0){
                q.push(j);
            }
        }
    }
    for(int i = 0; i < cnt; i ++ ) cout << ans[i] << ' ';
    cout << endl;
}
void solve(){
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i ++ ){
        int x;
        while(cin >> x, x){
            add(i, x);
            d[x] ++;
        }
    }
    topsort();
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