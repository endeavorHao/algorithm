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
    vector<int> s1, s2, s3;
    for(int i = 0, ai; i < n; i ++ ){
        cin >> ai;
        string s;
        cin >> s;
        if(s[0] == '1' && s[1] == '1') s3.push_back(ai);
        else if(s[0] == '1') s1.push_back(ai);
        else if(s[1] == '1') s2.push_back(ai);
    }
    if(s1.size())
        sort(all(s1));
    if(s2.size()) sort(all(s2));
    if(s3.size()) sort(all(s3));
    int ans = 1e18;
    if(s1.size() && s2.size()) ans = s1[0] + s2[0];
    if(s3.size()) ans = min(ans, s3[0]);
    if(ans == 1e18) cout << -1 << endl;
    else cout << ans << endl;
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