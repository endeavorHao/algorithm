#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	string s = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679.";
    int n;
    cin >> n;
    cout << "3.";
    for(int i = 0; i < n; i ++ )
        cout << s[i];
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