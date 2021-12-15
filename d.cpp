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
		int n, k; cin >> n >> k;
		vll v(n); for(ll& i : v) cin >> i;
		ll s = 0; sort(v.begin(), v.end());
		for(int i = 0; i < n-2*k; i++) {
			s += v[i];
		}
		map<int, int> m;
		for(int i = n-2*k; i < n; i++) {
			m[v[i]]++;
		}
		int ma = 0;
		for(auto it : m) ma = max(ma, it.second);
		if(ma > k) cout << s+ma-k << "\n";
		else cout << s << "\n";
	}
	return 0;
}
