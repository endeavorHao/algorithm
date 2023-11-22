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

int a[N], b[N];
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

int get(int x, int p) {
    int s = 0;
    while(x > 1) {
        s += x / p;
        x /= p;
    }
    return s;
}

void mul(int r[N], int &len, int p) {
    int t = 0;
    for(int i = 0; i < len; i ++ ) {
        t += r[i] * p;
        r[i] = t % 10;
        t /= 10;
    }
    while(t) r[len ++ ] = t % 10, t /= 10;
}

int C(int x, int y, int r[N]) {
    int len = 1;
    r[0] = 1;
    for(int i = 0; i < cnt; i ++ ) {
        int p = prime[i];
        int s = get(x, p) - get(y, p) - get(x - y, p);
        while(s -- ) mul(r, len, p);
    }
    return len;
}

void sub(int a[], int al, int b[], int bl) {
    for(int i = 0, t = 0; i < al; i ++ ) {
        t += a[i] - b[i];
        if(t < 0) a[i] = t + 10, t = -1;
        else a[i] = t, t = 0;
    }
}

void solve(){
	int n, m;
    cin >> n >> m;
    init(N - 1);
    int al = C(n + m, n, a);
    int bl = C(n + m, m - 1, b);

    sub(a, al, b, bl);
    int k = al - 1;
    while(!a[k] && k > 0) k --;
    while(k >= 0) cout << a[k --];
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