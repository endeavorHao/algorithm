#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 998244353;
typedef pair<int, int> PII;
int n, m;
int a[N];
int qmi(int a, int b){
  int res = 1;
  while(b){
    if(b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
void solve(){
    cin >> n >> m;
    int st = 1, ed = 2;
    while(st * 2 + 1 < n){
        st = st * 2 + 1;
        ed *= 2;
    }

    int k = st + ed - n;
    if(k > m) k = m;
    int res1 = 1, res2 = 1;
    res1 = qmi(st, k);
    res2 = qmi(ed, k);
    st = st * 2 + 1;
    ed *= 2;
    m -= k;
    while(m > 0){
        int k = ed;
        if(k > m) k = m;
        res1 = res1 * qmi(st, k) % mod;
        res2 = res2 * qmi(ed, k) % mod;
        st = st * 2 + 1;
        ed *= 2;
        m -= k;
    }
    cout << res1 * qmi(res2, mod - 2) % mod << endl;

}

signed main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
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


