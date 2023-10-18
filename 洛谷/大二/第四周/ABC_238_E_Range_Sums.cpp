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

int p[N];

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void solve(){
	int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n + 1; i ++ ) p[i] = i;
    while(q -- ) {
        int l, r;
        cin >> l >> r;
        int pa = find(l), pb = find(r + 1);
        if(pa != pb) {
            p[pa] = pb;
        }
    }
    if(find(1) == find(n + 1)) cout << "Yes" << endl;
    else cout << "No" << endl;
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