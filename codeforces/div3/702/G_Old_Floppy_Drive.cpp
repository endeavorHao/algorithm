#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
    int n, m;
    cin >> n >> m;
    int sum = 0;
    vector<PII> v;
    for(int i = 0, a; i < n; i ++ ){
        cin >> a;
        sum += a;
        if(not i or sum > v.back().first) v.push_back({sum, i});
    }
    for(int i = 0; i < m; i ++ ){
        int x;
        cin >> x;
        if(sum <= 0){
            if(x > v.back().first) cout << "-1 ";
            else cout << lower_bound(v.begin(), v.end(), make_pair(x, 0LL))->second << " ";
        }
        else{
            int r = max(0LL, (x - v.back().first + sum - 1) / sum);
            cout << lower_bound(v.begin(), v.end(), make_pair(x - r * sum, 0LL))->second + r * n << " ";
        }
    }
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