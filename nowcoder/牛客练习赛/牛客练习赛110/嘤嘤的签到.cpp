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
	string s;
	cin >> s;
	vector<int> cnt1(n + 1), cnt4(n + 1);
	for(int i = 0; i < n; i ++ ){
		cnt1[i + 1] = cnt1[i];
		cnt4[i + 1] = cnt4[i];
		if(s[i] == '1') cnt1[i + 1] ++;
		else if(s[i] == '4') cnt4[i + 1] ++;
	}
	int ans = 0;
	for(int i = 1, j = 0; i <= n; i ++ ){
		while(cnt1[i] > cnt1[j] && cnt4[i] > cnt4[j]) j ++;
		ans += i - j;
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