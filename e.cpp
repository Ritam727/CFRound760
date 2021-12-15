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
		ll n; cin >> n;
		ll s = n*(n+1)/2, sum = 0;
		vll v(n); for(ll& i : v) {
			cin >> i; sum += i;
		}
		vll ans(n);
		for(int i = 0; i < n; i++) {
			ll temp = sum+s*(v[(n+i-1)%n]-v[i]);
			if(temp <= 0 || temp%(n*s)) {
				cout << "NO\n";
				goto end;
			}
			ans[i] = temp/(n*s);
		}
		cout << "YES\n";
		for(ll i : ans) cout << i << " ";
		cout << "\n";
		end: 
			continue;
	}
	return 0;
}
