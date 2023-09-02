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
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i ++ ){
        int cnt;
        cin >> cnt;
        while(cnt -- ){
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    int x;
    cin >> x;
    vector<PII> ans;
    for(int i = 0; i < n; i ++ ){
        for(auto u: a[i]){
            if(u == x) ans.push_back({a[i].size(), i + 1});
        }
    }
    if(!ans.size()){
        cout << 0 << endl;
        return;
    }
    sort(ans.begin(), ans.end());
    int cnt = 1;
    for(int i = 1; i < ans.size(); i ++ ){
        if(ans[i].x == ans[i - 1].x){
            cnt ++;
        }else break;
    }
    cout << cnt << endl;
    for(int i = 0; i < cnt; i ++ ){
        cout << ans[i].y << ' ';
    }
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