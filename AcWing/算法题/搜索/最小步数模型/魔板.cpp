#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int g[4][2];
map<string, string> mp;
map<string, int> dist;
string get(string s, int k){
	if(k == 0){
		for(int i = 1; i <= 4; i ++ ) swap(s[i], s[i + 4]);
		swap(s[1], s[4]), swap(s[2], s[3]);
		swap(s[5], s[8]), swap(s[6], s[7]);
	}else if(k == 1){
		char c = s[4], c2 = s[8];
		for(int i = 4; i >= 2; i -- ){
			s[i] = s[i - 1], s[i + 4] = s[i + 4 - 1];
		}
		s[1] = c, s[5] = c2;
		swap(s[5], s[6]), swap(s[8], s[7]);
		swap(s[5], s[8]), swap(s[6], s[7]);
	}else{
		char c = s[2];
		s[2] = s[6], s[6] = s[7], s[7] = s[3], s[3] = c;
		swap(s[5], s[8]), swap(s[6], s[7]);
		swap(s[2], s[7]), swap(s[5], s[8]);
	}
	return s;
}
int bfs(string start, string end){
	queue<string> q;
	q.push({start});
	dist[start] = 0;
	mp[start] = "";
	while(q.size()){
		auto t = q.front();
		q.pop();
		if(t == end) return dist[t];
		for(int i = 0; i < 3; i ++ ){
			string x = get(t, i);
			if(!dist.count(x)){
				dist[x] = dist[t] + 1;
				string y = mp[t];
				mp[x] = y + (char)(i + 'A');
				q.push(x);
			} 
		}
	}
	return -1;
}
void solve(){
	string start = " ", end = " ";
	for(int i = 0; i < 8; i ++ ){
		int c;
		cin >> c;
		end += c + '0';
		start += i + '1';
	}
	cout << bfs(start, end) << endl;
	if(dist[end])
	cout << mp[end] << endl;
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