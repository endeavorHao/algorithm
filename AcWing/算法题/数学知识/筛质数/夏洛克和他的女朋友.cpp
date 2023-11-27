/*
    质数与合数可以分为一个二分图
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
int primes[N], cnt;
bool st[N];
void get_prime(int n){
    for(int i = 2; i <= n; i ++ ) {
        if(!st[i]) primes[cnt ++ ] = i;
        for(int j = 0; primes[j] * i <= n; j ++ ) {
            st[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }
}
void solve(){
	int n;
    cin >> n;
    get_prime(n + 1);
    if(n <= 2) cout << 1 << endl;
    else cout << 2 << endl;
    for(int i = 1; i <= n; i ++ ) {
        if(!st[i + 1]) cout << 1 << " \n"[i == n];
        else cout << 2 << " \n"[i == n];
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