#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int p[N], sz[N];
int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}
void solve(){
    int n, m, t, q;
    cin >> n >> m >> t >> q;
    map<int, int> mp;
    int cnt = 0;
    for(int i = 1; i <= n; i ++ ) p[i] = i, sz[i] = 1;
    mp[1] = ++ cnt;
    while(t -- ) {
        int a, b;
        cin >> a >> b;
        if(!mp[a]) mp[a] = ++ cnt;
        if(!mp[b]) mp[b] = ++ cnt;
        a = mp[a], b = mp[b];
        int pa = find(a), pb = find(b);
        if(pa != pb) {
            sz[pb] += sz[pa];
            p[pa] = pb;
        }
    }
    int x = sz[find(mp[1])];
    for(int i = 1; i <= m; i ++ ) p[i] = i, sz[i] = 1;
    cnt = 0;
    mp[-1] = ++ cnt;
    while(q -- ) {
        int a, b;
        cin >> a >> b;
        if(!mp[a]) mp[a] = ++ cnt;
        if(!mp[b]) mp[b] = ++ cnt;
        a = mp[a], b = mp[b];
        int pa = find(a), pb = find(b);
        if(pa != pb) {
            sz[pb] += sz[pa];
            p[pa] = pb;
        }
    }
    cout << min(x, sz[find(mp[-1])]) << endl;
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