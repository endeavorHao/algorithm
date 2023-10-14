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
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) p[i] = i;
    while(m -- ) {
        int x, a, b;
        cin >> x >> a >> b;
        if(x == 1) {
            int pa = find(a), pb = find(b);
            if(pa != pb) {
                p[pa] = pb;
            }
        }else {
            int pa = find(a), pb = find(b);
            if(pa == pb) cout << "Y" << endl;
            else cout << "N" << endl;
        }
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