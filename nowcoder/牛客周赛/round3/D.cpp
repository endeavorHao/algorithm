#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1e9 + 7;
typedef pair<int, int> PII;
int n, m;
int a[N];
int qmi(int a, int b){
    int ans = 1 % mod;
    while(b){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
void sovle(){
	cin >> n;
    int ans = 0;
    int m = n * n % mod;
    ans = (1 + m) % mod * m  % mod * qmi(2, mod - 2) % mod;
    ans *= 2;
    int t = m - (n - 2) * (n - 2);
    ans = (ans + (2 * (( n - 2 ) * (n - 2)) % mod * ( (m + m + 1) % mod - ((n - 2) * (n - 2)) % mod))% mod % mod*qmi(2, mod - 2) % mod) % mod;
    ans = (ans + ((n - 2 ) * 4) % mod * ((t + t + 1) % mod - ((n - 2) * 4) % mod) % mod * qmi(2 , mod - 2) % mod) % mod;
    cout << (ans  + mod) % mod << endl;
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
// 	cin >> T;
	while(T -- ){
		sovle();
	}
	return 0;
}


