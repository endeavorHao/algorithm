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
    vector<int> ans;
    for(int j = 0; j < 30; j ++ ){
        if(n >> j & 1) ans.push_back(j);
    }
    while(ans.size() >= 2){
        vector<int> temp;
        auto x =  ans.back();
        ans.pop_back();
        for(int j = 30; j >= 0; j -- ){
            if(x >> j & 1) temp.push_back(j);
        }
        cout << "2(";
        for(auto u: temp){
            if(u != temp.back()){
                cout << ""
            }
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