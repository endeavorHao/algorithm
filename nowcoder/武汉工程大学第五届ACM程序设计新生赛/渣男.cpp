#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	string s;
    string t = "npynpy";
    cin >> s;
    for(int i = 0; i + 6 <= s.size(); i ++ ){
        if(s.substr(i, 6) == t)  {
            cout << "Unhappy" << endl;
            return;
        }
    }
    cout << "Happy" << endl;
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