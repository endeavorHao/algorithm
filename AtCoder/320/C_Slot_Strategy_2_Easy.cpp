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
	int m;
    cin >> m;
    string s[3];
    for(int i = 0; i < 3; i ++ ) cin >> s[i];
    vector<int> cnt(10);
    for(int i = 0; i < 10; i ++ ){
        int ma = 0;
        vector<vector<int>> ar(3);
        for(int j = 0; j < 3; j ++ ){
            for(int k = 0; k < m; k ++ ){
                if(s[j][k] - '0' == i) ar[j].push_back(k);
            }
        }
        if(ar[0].size() == 0 || ar[1].size() == 0 || ar[2].size() == 0) ma = INF;
        else{
            int mi = 1e18;
            for(int s1 = 0; s1 < ar[0].size(); s1 ++ ){
                for(int s2 = 0; s2 < ar[1].size(); s2 ++){
                    for(int s3 = 0; s3 < ar[2].size(); s3 ++ ){
                        int a = ar[0][s1], b = ar[1][s2], c = ar[2][s3];
                        vector<int> sum;
                        sum.push_back(a), sum.push_back(b), sum.push_back(c);
                        sort(all(sum));
                        if(sum[0] == sum[1] && sum[1] == sum[2]) mi = min(mi, sum[0] + 2 * m);
                        else if(sum[0] == sum[1]) mi = min(mi, sum[0] + m);
                        else if(sum[1] == sum[2]) mi = min(mi, sum[1] + m);
                        else mi = min(mi, sum[2]); 
                    }
                }
            }
            ma = mi;
        }
        cnt[i] = ma;
    }
    int res = 1e18;
    for(int i = 0; i < 10; i ++ ){
        res = min(res, cnt[i]);
    }
    if(res == INF) cout << -1 << endl;
    else cout << res << endl;
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