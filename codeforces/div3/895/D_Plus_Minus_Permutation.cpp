#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 600010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
void solve(){
	int n, x, y;
    cin >> n >> x >> y;
    int t = gcd(x, y);
    int h = x * y / gcd(x, y);
    int a = n / x, b = n / y, c = n / h;
    int t1 = a - c, y2 = b - c;
    cout << (n + n - t1 + 1) * t1 / 2 - (1 + y2) * y2 / 2 << endl;
    
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}