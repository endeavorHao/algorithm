#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void dfs(int x) {
    if(x == 0) cout << 0;
    else if(x == 1) cout << "2(0)";
    else if(x == 2) cout << "2";
    else {
        bool flag = false;
        for(int i = 31; i >= 0; i -- ) {
            if(x >> i & 1) {
                if(!flag) {
                    flag = true;
                } else cout << "+";
                
                if(i == 1) cout << 2;
                else {
                    cout << "2(";
                    dfs(i);
                    cout << ")";
                }
            }
        }
    }
}

void solve(){
	int n;
    cin >> n;
    dfs(n);
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