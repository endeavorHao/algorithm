#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	while(s.size() > 1){
		string t = "";
		for(int i = 0; i < s.size() - 1; i ++ ){
			int x = s[i + 1] - '0';
			for(int j = 0; j < x; j ++ ) 
				t += s[i];
		}
		s = t;
		cout << t << endl;
		cnt ++;
	}
	cout << cnt << endl;
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