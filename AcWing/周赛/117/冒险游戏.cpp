#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 300010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    int ans = 0;
    for(int i = 0; i < s.size(); i += 2 ){
        s[i] = toupper(s[i]);
        mp[s[i]] ++;
        if(mp[s[i + 1]] >= 1) mp[s[i + 1]] --;
        else ans ++;
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