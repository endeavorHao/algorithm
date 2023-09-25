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
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    vector<PII> ans;
    int l = 0, dmax = 0;
    for(int i = 1; i < n; i ++ ){
        if(a[i] < a[i - 1]){
            if(a[i - 1] - a[l] > dmax){
                ans.clear();
                ans.push_back({l, i - 1});
                dmax = a[i - 1] - a[l];
            }else if(a[i - 1] - a[l] == dmax){
                ans.push_back({l, i - 1});
            }
            l = i;
        }
    }
    if(a[n - 1] - a[l] > dmax){
        ans.clear();
        ans.push_back({l, n - 1});
    }else if(a[n - 1] - a[l] == dmax){
        ans.push_back({l, n - 1});
    }
    sort(all(ans));
    for(auto [x, y]: ans) cout << x + 1 << ' ' << y + 1 << ' ';
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