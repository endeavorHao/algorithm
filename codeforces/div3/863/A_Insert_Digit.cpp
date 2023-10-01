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
	int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    string ans;
    bool ok = false;
    for(int i = 0; i < n; i ++ ){
        if(s[i] - '0' >= x) ans += s[i];
        else{
            if(!ok){
                ans += x + '0';
                ok = true;
            }
            ans += s[i];
        }
    }
    if(!ok) ans += x + '0';
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