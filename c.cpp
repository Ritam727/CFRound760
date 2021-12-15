#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define tests int t; cin >> t; while(t--)
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
using namespace std;

ll gcd(ll a, ll b) {
	if(a == 0) return b;
	if(b == 0) return a;
	if(a%2 == 0 && b%2 == 0) return 2*gcd(a/2, b/2);
	if(a%2 == 0 && b%2 == 1) return gcd(a/2, b);
	if(a%2 == 1 && b%2 == 0) return gcd(a, b/2);
	if(a < b) swap(a, b);
	return gcd(b, a-b);
}

void solve() {
	int n; cin >> n;
	vll v(n); for(ll& i : v) cin >> i;
	ll h1 = 0, h2 = 0;
	for(int i = 0; i < n; i += 2) h1 = gcd(h1, v[i]);
	for(int i = 1; i < n; i += 2) h2 = gcd(h2, v[i]);
	if(h1 == h2) {
		cout << "0\n";
		return;
	}
	bool f1 = false, f2 = false;
	for(int i = 0; i < n-1; i++) {
		if(gcd(v[i], v[i+1]) == h1 || gcd(v[i], v[i+1])%h1 == 0) {
			f1 = true;
		}
		if(gcd(v[i], v[i+1]) == h2 || gcd(v[i], v[i+1])%h2 == 0) {
			f2 = true;
		}
	}
	if(f1 && f2) {
		cout << "0\n";
	} else if(!f1 && !f2) {
		cout << max(h1, h2) << "\n";
	} else if(!f1) {
		cout << h1 << "\n";
	} else {
		cout << h2 << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	tests {
		solve();
	}
	return 0;
}
