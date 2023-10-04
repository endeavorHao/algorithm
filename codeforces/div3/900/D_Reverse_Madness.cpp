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
    string s;
    cin >> s;
    vector<int> L(k + 1), R(k + 1);
    for(int i = 1; i <= k; i ++ ) cin >> L[i];
    for(int i = 1; i <= k; i ++ ) cin >> R[i];
    int q;
    cin >> q;
    map<int, int> ans;
    vector<int> b(n + 1);
    while(q -- ){
        int x;
        cin >> x;
        int l = 1, r = k;
        while(l < r){
            int mid = l + r >> 1;
            if(x <= R[mid]) r = mid;
            else l = mid + 1;
        }
        l = 1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(x >= L[mid]) l = mid;
            else r = mid - 1;
        }
        l = min(x, R[r] + L[r] - x), r = max(R[r] + L[r] - x, x);
        ans[l - 1] = r - 1;
        b[l - 1] ++, b[r] --;
    }
    for(int i = 0; i < n; i ++ ) if(i) b[i] += b[i - 1];
    for(int i = 0; i < n; i ++ ){
        if(b[i] & 1){
            int r = ans[i];
            for(int j = i, cnt = 0; j <= r; j ++, cnt ++ ){
                if(b[j] & 1){
                    cout << s[r - cnt];
                }else cout << s[j];
            }
            i = r;
        }else cout << s[i];
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