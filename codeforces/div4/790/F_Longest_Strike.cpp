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
	int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    map<int, int> mp;
    for(int i = 0; i < n; i ++ ) mp[a[i]] ++;
    vector<int> alls;
    for(auto [x, y]: mp){
        if(y >= k) alls.push_back(x);
    }
    sort(all(alls));
    if(alls.empty()){
        cout << -1 << endl;
        return;
    }
    int maxv = 0, cnt = 0;
    int l = alls[0], r = alls[0];
    for(auto i = 1; i < alls.size(); i ++ ){
        if(alls[i] - alls[i - 1] == 1){
            cnt ++;
            if(cnt > maxv){
                r = alls[i];
                l = alls[i - cnt];
                maxv = cnt;
            }
        }else{
            cnt = 0;
        }
    }
    if(alls.size()) cout << l << ' ' << r << endl;
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