#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	string s;
    cin >> s;
    vector<int> ans;
    int sum = 0;
    int k = s.rfind('#');
    for(int i = 0; s[i]; i ++ ){
        char c = s[i];
        if(c == '(') sum ++;
        else if(c == ')'){
            sum --;
            if(sum < 0){
                if(ans.back() >= 2){
                    ans.back() --;
                    sum = 0;
                }else{
                    cout << -1 << endl;
                    return;
                }
            }
        }else{
            if(i != k){
                sum --;
                ans.push_back(1);
            }else{
                if(sum)
                    ans.push_back(sum);
                else{
                    cout << -1 << endl;
                    return ;
                }
                sum = 0;
            }
        }
    }
    if(!ans.size() || sum){
        cout << -1 << endl;
    }else{
        for(auto u: ans) cout << u << endl;
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