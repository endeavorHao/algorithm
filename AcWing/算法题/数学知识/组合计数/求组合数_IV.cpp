#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 10010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int prime[N], cnt;
bool st[N];

int c[N];

void init(int n) {
    for(int i = 2; i <= n; i ++ ) {
        if(!st[i]) prime[cnt ++ ] = i;
        for(int j = 0; prime[j] <= n / i; j ++ ) {
            st[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
}

int get(int x, int p) {
    int s = 0;
    while(x > 1) {
        s += x / p;
        x /= p;
    }
    return s;
}

void mul(int c[N], int &len, int p) {
    int t = 0;
    for(int i = 0; i < len; i ++ ) {
        t += c[i] * p;
        c[i] = t % 10;
        t /= 10;
    }
    while(t) c[len ++ ] = t % 10, t /= 10;
}


void solve(){
	int a, b;
    cin >> a >> b;
    int len = 1;
    c[0] = 1;
    init(N - 1);
    for(int i = 0; i < cnt; i ++ ) {
        int p = prime[i];
        int s = get(a, p) - get(b, p) - get(a - b, p);
        while(s --) mul(c, len, p);
    }
    while(len > 0) cout << c[ -- len];
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