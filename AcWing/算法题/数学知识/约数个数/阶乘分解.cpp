/*
    n!分解质因数：
        因为对于一个质数p n中有n/p个是p的倍数
        因此将所有的质数的n/p加上
        又因为4类似的数会被多个同样质数分解 所以还要加上所有p的倍数次
*/
#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int prime[N], cnt;
bool st[N];
void get_prime(int n){
    for (int i = 2; i <= n; i ++ ) {
        if(!st[i]) prime[cnt ++ ] = i;
        for(int j = 0; prime[j] * i <= n; j ++ ) {
            st[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
}
void solve(){
    int n;
    cin >> n;
	get_prime(n);
    for(int i = 0; i < cnt; i ++ ) {
        int p = prime[i];
        int ans = 0;
        for(int k = n; k > 0; k /= p) ans += k / p;
        cout << p << " " << ans << endl; 
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