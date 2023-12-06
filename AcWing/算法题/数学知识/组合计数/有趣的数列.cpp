#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 2000010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int n, p;
int prime[N], cnt;
bool st[N];

void init(int n) {
    for(int i = 2; i <= n; i ++ ) {
        if(!st[i]) prime[cnt ++ ] = i;
        for(int j = 0; prime[j] <= n / i; j ++ ) {
            st[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
}

int qmi(int a, int b, int p) {
    int res = 1;
    while(b) {
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int get(int a, int p) {
    int s = 0;
    while(a) {
        s += a / p;
        a /= p;
    }
    return s;
}


int C(int a, int b) {
    if(a < b) return 0;
    int res = 1;
    for(int i = 0; i < cnt; i ++ ) {
        int pri = prime[i];
        int s = get(a, pri) - get(b, pri) - get(a - b, pri);
        res = res * qmi(pri, s, p) % p;
    }
    return res;
}

void solve(){
    cin >> n >> p;
    init(N - 1);
    cout << (C(2 * n, n) - C(2 * n, n - 1) + p) % p << endl;
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