#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, k;
    cin >> n >> k;
    vector<int> s(n), t(n);
    for(int i = 0; i < n; i ++ ) cin >> s[i] >> t[i];
	priority_queue<int, vector<int>, greater<int>> heap;
    for(int i = 0; i < n; i ++ ) { 
        if(i < k){
			heap.push(s[i] + t[i]);
			cout << s[i] + t[i] << endl;
		}else{
		    int res = 0;
    		if(s[i] <= heap.top()){
    			res = heap.top() + t[i];
    		}else{
    			res = s[i] + t[i];
    		}
    		cout << res << endl;
    		heap.pop();
    		heap.push(res);
		}
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