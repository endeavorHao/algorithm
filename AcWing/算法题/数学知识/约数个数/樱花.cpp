#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int prime[N], cnt;
bool st[N];

void init(int n){
    for (int i = 2; i <= n; i ++ ) {
        if(!st[i]) prime[cnt ++ ] = i;
        for (int j = 0; prime[j] * i <= n; j ++ ) {
            st[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
}

void solve(){
	int n;
    cin >> n;
    init(n);
    int ans = 1;
    for(int i = 0; i < cnt; i ++ ) {
        int s = 0;
        int p = prime[i];
        for(int j = n; j; j /= p) s += j / p;
        ans = ans * (1 + s * 2) % mod;
    }
    cout << ans << endl;
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