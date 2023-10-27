/*
    暴力的做法就是求出所有d的约数然后一一判断
    因为int范围内最多约数个数为1600因此时间复杂度允许
    如果暴力求d的约数时间复杂度为T*sqrt(d) = 2000 * sqrt(2e9)因此会超时
    所以我们需要先预处理所有质数
    这样时间复杂度降为T*sqrt(d)/log(d)
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
    if(u == cntf) {
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