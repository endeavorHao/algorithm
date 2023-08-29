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
    vector<int> b(n);
    vector<int> ans;
    for(int i = 0; i < n; i ++ ) cin >> b[i];
    for(int i = 0; i < n; i ++ ){
        if(!i) ans.push_back(b[i]);
        else{
            if(b[i] >= b[i - 1]) ans.push_back(b[i]);
            else {
                ans.push_back(b[i]);
                ans.push_back(b[i]);
            }
        }
    }
    cout << ans.size() << endl;
    for(auto u: ans) cout << u << ' ';
    cout << endl;
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