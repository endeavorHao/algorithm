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
    // 找异或和为0的区间
    mt19937 mt;
    map<int, int> count;
    map<int, int> mp;
    map<int, int> pre;
    vector<int> s(n + 1), p(n + 1);
    count[0] = 1;
    int ans = 0;
    for(int i = 1, j = 0, ai; i <= n; i ++ ){
        cin >> ai;
        if(not mp.count(ai)){
            mp[ai] = mt();
        }
        s[i] = s[i - 1] ^ mp[ai];
        count[s[i]] ++;
        if(not pre.count(ai)){
            pre[ai] = i;
            continue;
        }
        p[i] = pre[ai];  // p[i]表示点i上ai之前在哪个位置上出现
        pre[ai] = i;
        while(j < p[p[i]]){  // 双指针
            count[s[j]] --;
            j ++ ;
        }
        ans += count[s[i]] - 1;
    }
    cout << ans << endl;
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