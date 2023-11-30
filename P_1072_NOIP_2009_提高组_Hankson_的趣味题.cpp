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

int prime[N], cnt;
bool st[N];
PII facter[N];
int divider[N];
int cntd;
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
        divider[cntd ++ ] = p;
        return ;
    }
    for(int i = 0; i <= facter[u].y; i ++ ) {
        dfs(u + 1, p);
        p *= facter[u].x;
    }
}

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int t = d;
    cntf = 0, cntd = 0;
    for(int i = 0; i < cnt; i ++ ) {
        int p = prime[i];
        if(p <= t / p) {
            if(t % p == 0) {
                int s = 0;
                while(t % p == 0) {
                    t /= p;
                    s ++;
                }
                facter[cntf ++ ] = {p, s};
            }
        }
        else break;
    }
    if(t > 1) facter[cntf ++ ] = {t, 1};
    dfs(0, 1);
    int ans = 0;
    for(int i = 0; i < cntd; i ++ ) {
        int x = divider[i];
        // lcm(a, b) = c;
        // c = a * b / __gcd(a, b);
        if(__gcd(x, a) == b && x * c / __gcd(x, c) == d) {
            ans ++;
        }
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