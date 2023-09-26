#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
void solve(){
	int n, m, k, l, d;
    cin >> n >> m >> k >> l >> d;
    vector<PII> row(n + 1), col(m + 1);
    while(d -- ){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2){
            col[min(y1, y2)].x ++;
        }else{
            row[min(x1, x2)].x ++;
        }
    }
    for(int i = 0; i <= n; i ++ ) row[i].y = i;
    for(int i = 0; i <= m; i ++ ) col[i].y = i;
    sort(all(row), greater<PII>()), sort(all(col), greater<PII>());
    vector<int> ans;
    for(int i = 0; i < k; i ++ ) ans.push_back(row[i].y);
    sort(all(ans));
    for(auto x: ans) cout << x << ' ';
    cout << endl;
    ans.clear();  
    for(int i = 0; i < l; i ++ ) ans.push_back(col[i].y);
    sort(all(ans));
    for(auto x: ans) cout << x << ' ';
    cout << endl;
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