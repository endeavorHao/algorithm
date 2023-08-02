#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int phi(int x){
    int res = x;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
        {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    if (x > 1) res = res / x * (x - 1);
    return res;
}
int qmi(int a, int b, int p){
	int ans = 1 % p;
	a %= p;
	while(b){
		if(b & 1) ans = ans * a % p;
		b >>= 1;
		a = a * a % p;
	}
	return ans;
}
void solve(){
	int n, p;
	cin >> n >> p;
	int u = phi(p);
	if(p / 2 != 0){
		int t = qmi(2, n, u);
		int ans = qmi(2, t, p);
		cout << ans << endl;
	}else if(n >= u){
		int t = qmi(2, n, 2 * u);
		int ans = qmi(2, t, p);
		cout << ans << endl;
	}else{
		int t = qmi(2, n, p);
		int ans = qmi(2, t, p);
		cout << ans << endl;
	}
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