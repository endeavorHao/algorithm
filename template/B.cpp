#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int g[4][2];
string get(string s, int k){
	if(k == 0){
		for(int i = 0; i < 4; i ++ ) swap(s[i], s[i + 4]);
	}else if(k == 1){
		char c = s[3], c2 = s[7];
		for(int i = 3; i >= 1; i -- ){
			s[i] = s[i - 1], s[i + 4] = s[i + 4 - 1];
		}
		s[0] = c, s[4] = c2;
	}else{
		char c = s[1];
		s[1] = s[5], s[5] = s[6], s[6] = s[2], s[2] = c;
	}
	return s;
}
void bfs(string start, string end){
	queue<string> q;
	map<string, string> mp;
	map<string, int> dist;
	q.push({start});
	dist[start] = 0;
	mp[start] = "";
	while(q.size()){
		auto t = q.front();
		q.pop();

		for(int i = 0; i < 3; i ++ ){
			string x = get(x, i);
			cout << x << endl;
		}
	}
}
void solve(){
	string start = "", end = "";
	for(int i = 0; i < 8; i ++ ){
		int c;
		cin >> c;
		start += c + '0';
		end += i + '1';
	}
	cout << start << ' ' << end;
	bfs(start, end);
}
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
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