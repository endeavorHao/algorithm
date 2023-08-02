#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	string s;
	cin >> s;
	s = ' ' + s;
	vector<int> cnt(10);
	cnt[0] = 1;
	for(int i = 1; i < s.size(); i ++ ){
		vector<int> temp(10);
		int x = s[i] - '0';
		for(int j = 0; j < 9; j ++ ){
			temp[j] = (cnt[(j - x + 9) % 9] + cnt[j]) % mod;
		}
		cnt = temp;
	}
	cout << cnt[0] - 1 << endl;
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