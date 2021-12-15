#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define tests int t; cin >> t; while(t--)
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	tests {
		int n; cin >> n;
		vector<string> v(n-2);
		for(string& s : v) cin >> s;
		if(n == 3) {
			cout << v[0] << "b\n";
			continue;
		}
		bool f = false;
		for(int i = 0; i < n-3; i++) {
			cout << v[i][0];
			if(v[i][1] != v[i+1][0] && !f) {
				cout << v[i][1];
				f = true;
			}
		}
		cout << v[n-3];
		if(!f) cout << "a";
		cout << "\n";
	}
	return 0;
}
