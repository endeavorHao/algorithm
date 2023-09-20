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
	string s;
    cin >> s;
    int ans = 0;
    auto check = [&](int i, int j) ->bool{
        string t = s.substr(i, j - i + 1);
        string x = t;
        reverse(all(t));
        if(x == t) return true;
        else return false;
    };
    for(int i = 0; i < s.size(); i ++ ){
        for(int j = i; j < s.size(); j ++ ){
            if(check(i, j)) ans = max(ans, j - i + 1);
        }
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