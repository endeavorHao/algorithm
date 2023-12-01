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
    map<int, int> mp;
    for(int i = 0; i < n; i ++ ){
        int x;
        char c;
        cin >> x >> c;
        if(c == '.') mp[x] ++, mp[x + 1] --;
        else if(c == '+') mp[0] ++, mp[x] --;
        else mp[x + 1] ++;
    }
    int ans = 0;
    int sum = 0;
    for(auto [x, y]: mp){
        sum += y;
        ans = max(ans, sum);
    }
    cout << ans << endl;
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