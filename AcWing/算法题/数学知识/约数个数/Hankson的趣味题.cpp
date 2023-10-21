/*
    gcd(x, y) = p
    因此gcd(x / p, y /p) = 1
    因此问所有n/p的互质数和
*/
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
int divider[N], cntd;
PII factor[N];
int cntf;

void init(int n) {
    for(int i = 2; i <= n; i ++ ) {
        if(!st[i]) prime[cnt ++ ] = i;
        for(int j = 0; prime[j] <= n / i; j ++ ) {
            st[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
}

void dfs(int u, int p) {
    if(u > cntf) {
        divider[cntd ++] = p;
        return;
    }
    for(int i = 0; i <= factor[u].y; i ++ ) {
        dfs(u + 1, p);
        p *= factor[u].x;
    }
}

void solve(){  
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int t = d;
    cntf = 0;
    for(int i = 0; i < cnt; i ++ ) {
        int p = prime[i];
        if(t % p == 0) {
            int s = 0;
            while(t % p == 0) t /= p, s ++ ;
            factor[cntf ++ ] = {p, s};
        }
    }
    if(t > 1) factor[cntf ++ ] = {t, 1};
    cntd = 0;
    dfs(0, 1);
    int ans = 0;
    for(int i = 0; i < cntd; i ++ ) {
        int x = divider[i];
        if(__gcd(x, a) == b && x * c / __gcd(x, c) == d) ans ++;
    }
    cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    init(50010);
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}