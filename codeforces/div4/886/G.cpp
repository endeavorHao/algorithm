#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1e9 + 7;
typedef pair<int, int> PII;
int n, m;
int a[N], lcm[N];
int f(int x){
    int ans = 0;
    for(int i = 2; i <= x / i; i ++ ){
        if(x % i == 0){
            while(x % i == 0){
                ans ++;
                x /= i;
            }
        }
    }
    if(x > 1) ans ++;
    return ans;
}
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
void solve(){
	cin >> n;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int i = 1; i <= n; i ++ )
        for(int j = i; j <= n; j ++ ){
            
        }
    int ans = 0;
    for(int i = 1; i <= n; i ++ ){
        int x = 0;
        for(int j = i; j <= n; j ++ ){
            int t = gcd(x, a[j]);
            ans = (ans + f())
        }
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