#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int a, b;
    cin >> a >> b;
    vector<int> nums;
    while(b) nums.push_back(b % 10), b /= 10;
    int ans = 0;
    for(int i = 0; i < nums.size(); i ++ ){
        ans += a * nums[i];
    }
    cout << ans << endl;
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