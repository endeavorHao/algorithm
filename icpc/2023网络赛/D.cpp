#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int p[N];
int sz[N];
int l[N];
bool vis[N];
int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}
void solve(){
	int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) p[i] = i, sz[i] = 1;
    for(int i = 0; i < m; i ++ ){
        int a, b;
        cin >> a >> b;
        int pa = find(a), pb = find(b);
        if(pa != pb){
            sz[pb] += sz[pa];
            l[pb] += l[pa] + 1;
            p[pa] = pb;
        }else{
            l[pa] ++;
        }
    }
    vector<PII> ans;
    for(int i = 1; i <= n; i ++ ){
        int px = find(i);
        if(vis[px]) continue;
        ans.push_back({sz[px], l[px]});
        vis[px] = true;
    }
    sort(all(ans));
    int res = 0;
    for(auto [x, y]: ans){
        res += (x * (x - 1) / 2 - y);
    }
    if(!res) cout << ans[0].x * ans[1].x << endl;
    else cout << res << endl;
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