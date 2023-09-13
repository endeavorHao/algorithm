#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
struct node{
    int a, b, g, k, id;
};
void solve(){
	int n;
    cin >> n;
    int ans = -1;
    vector<node> s(n + 1);
    for(int i = 0; i < n; i ++ ){
        int a, b, g, k;
        cin >> a >> b >> g >> k;
        s[i] = {a, b, g, k, i + 1};
    }
    int x, y;
    cin >> x >> y;
    for(auto [a, b, g, k, id] : s){
        int mx = a + g - 1, my = b + k - 1;
        if(x >= a && x <= mx && y >= b && y <= my) ans = id; 
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