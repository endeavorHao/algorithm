#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
string s[N];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i ++ ) cin >> s[i];
	string s1 = "", s2 = "";
	int cnt = 0;
	for(int i = 0; i < n; i ++ ) s1 += s[0][i], s2 += s[0][i] == '1' ? '0' : '1';
	for(int i = 0; i < n; i ++ ){
		if(s[i] == s1) cnt ++;
		if(s[i] != s1 && s[i] != s2){
			cout << "-1" << endl;
			return;
		}
	}

	int c = 0;
	for(int i = 0; i < n; i ++ ) c += s[0][i] == '1' ? 1 : 0;
	cout << min(cnt + min(c, n - c), n - cnt + min(c, n - c));
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