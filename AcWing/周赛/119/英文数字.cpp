#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
    string s1[] = {"zero", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine", "ten", "eleven",
    "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
    "seventeen", "eighteen", "nineteen"};
    string s2[10] = {"twenty", "thirty", "forty", "fifty", "sixty",
    "seventy", "eighty", "ninety"};
    int n;
    cin >> n;
    if(n < 20) cout << s1[n] << endl;
    else if(n % 10 == 0) cout << s2[n / 10 - 2];
    else cout << s2[n / 10 - 2] << '-' << s1[n % 10];
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