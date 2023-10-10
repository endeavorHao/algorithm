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
    vector<int> a(n + 1);
    a[0] = 2, a[1] = 3;
    for(int i = 2; i < n; i ++ ){
        int j = a[i - 1] + 1;
        while(j * 3 % (a[i - 1] + a[i - 2]) == 0) j ++;
        a[i] = j;
    }
    for(int i = 0; i < n; i ++ ) cout << a[i] << " \n"[i == n -1];
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