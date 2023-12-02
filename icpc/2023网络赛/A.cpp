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
	int n, m;
    cin >> n >> m;
    vector<string> str1, str2;
    set<string> s1, s2;
    for(int i = 0; i < n; i ++ ){
        string s;
        cin >> s;
        if(!s1.count(s)){
            str1.push_back(s);
        }
        s1.insert(s);
    }
    for(int i = 0; i < m; i ++ ){
        string s;
        cin >> s;
        if(!s2.count(s)){
            str2.push_back(s);
        }
        s2.insert(s);
    }
    n = str1.size(), m = str2.size();
    vector<string> ans;
    set<string> s3;
    for(int i = 0; i < max(n, m); i ++ ){
        if(i < n){
            ans.push_back(str1[i]);
        }
        if(i < m){
            ans.push_back(str2[i]);
        }
    }
    for(int i = 0; i < ans.size(); i ++ ){
        if(!s3.count(ans[i])) cout << ans[i] << endl;
        s3.insert(ans[i]);
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