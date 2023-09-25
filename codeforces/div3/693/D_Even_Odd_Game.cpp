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
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    priority_queue<int> b1, b2;
    for(int i = 0; i < n; i ++ ) 
        if(a[i] % 2 == 0) b1.push(a[i]);
        else b2.push(a[i]);
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; i ++ ){
        if(i % 2 == 0){
            if(b1.size() && b2.size()){
                if(b1.top() > b2.top()){
                    ans1 += b1.top();   
                    b1.pop();
                }else{
                    b2.pop();
                }
            }else if(b1.size()){
                ans1 += b1.top();
                b1.pop();
            }else{
                b2.pop();
            }
        }else{
            if(b1.size() && b2.size()){
                if(b2.top() > b1.top()){
                    ans2 += b2.top();   
                    b2.pop();
                }else{
                    b1.pop();
                }
            }else if(b2.size()){
                ans2 += b2.top();
                b2.pop();
            }else{
                b1.pop();
            }
        }
    }
    if(ans1 == ans2) cout << "Tie" << endl;
    else if(ans1 > ans2) cout << "Alice" << endl;
    else cout << "Bob" << endl;
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