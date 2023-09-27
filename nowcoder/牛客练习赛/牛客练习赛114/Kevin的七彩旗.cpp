#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, m;
    cin >> n >> m;
    map<int, int> mp;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }
    vector<PII> all;
    int cnt = 1;
    for(int i = n - 1; i >= 0; i -- ){
        if(i != n - 1 && a[i] + 1 == a[i + 1]){
            cnt ++;
            all.push_back({a[i], cnt});
        }else{
            all.push_back({a[i], 1});
            cnt = 1;
        }
    }
    sort(all.begin(), all.end(), [](PII a, PII b){
        if(a.x == b.x) return a.y > b.y;
        else return a.x < b.x;
    });
    int ans = 0;
    int x = 1;
    while(1){
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(all[mid].x >= x) r = mid;
            else l = mid + 1;
        }
        if(all[r].x == x){
            x += all[r].y;
            ans ++;
        }else{
            cout << -1 << endl;
            return;
        }
        if(x > m) {
            cout << ans << endl;
            return ;
        }
    }
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