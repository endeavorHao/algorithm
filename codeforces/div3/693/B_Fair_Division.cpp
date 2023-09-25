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
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i ++ ) cin >> a[i], sum += a[i];
    vector<int> dp(210);
    dp[0] = 1;
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < 200; j ++ ){
            dp[j + a[i]] |= dp[j];
        }
    }
    if(sum % 2 == 0 && dp[sum / 2]){
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
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