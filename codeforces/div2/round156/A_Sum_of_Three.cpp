#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n;
    cin >> n;
    if(n % 3) {
        int a = 1, b = 2, c = n - 3;
        if(c <= 3) cout << "NO" << endl;
        else {
            cout << "YES" << endl; 
            cout << a << ' ' << b << ' ' << c << endl; 
        }
    }else {
        int a = 1, b = 4, c = n - 5;
        if(c > 4) {
            cout << "YES" << endl; 
            cout << a << ' ' << b << ' ' << c << endl; 
        }
        else cout << "NO" << endl;
    }
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