#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i ++ ) {
        if(s[i] == '.') {
            s[i] = 'C';
        }
    }
    for(int i = 0; i < s.size(); i ++ ) {
        if(s[i] == 'L') {
            if (i != 0 and s[i - 1] == 'C') {
                s[i - 1] = '.';
            }
            if (i != s.size() - 1 and s[i + 1] == 'C') {
                s[i + 1] = '.';
            }
        }
    }
    cout << s << endl;
    return 0;
}