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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    vector<vector<int>> cnt(n + 1, vector<int>(30));
    for(int i = 1; i <= n; i ++ ){
        cnt[i] = cnt[i - 1];
        for(int j = 0; j < 30; j ++ ){
            if(a[i] >> j & 1) cnt[i][j] ++;
        }
    } 
    int q;
    cin >> q;
    while(q -- ){
        int L, k;
        cin >> L >> k;
        auto check = [&](int mid) -> bool{
            int x = 0;
            for(int i = 0; i < 30; i ++ ){
                if(cnt[mid][i] - cnt[L - 1][i] == mid - L + 1) x += 1 << i;
            }
            return x >= k;
        };
        int l = L, r = n;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }
        if(a[L] < k) cout << "-1" << " ";
        else cout << r << ' '; 
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