#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define tests int t; cin >> t; while(t--)
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
using namespace std;

bool check(vector<bool>& vis, vll& v, ll x) {
	for(int l = 0; l < 7; l++) {
		if(v[l] == x && !vis[l]) {
			vis[l] = true;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	tests {
		vll v(7); for(ll& i : v) cin >> i;
		for(int i = 0; i < 7; i++) {
			for(int j = i+1; j < 7; j++) {
				for(int k = j+1; k < 7; k++) {
					vector<bool> vis(7, false);
					vis[i] = vis[j] = vis[k] = true;
					if(!check(vis, v, v[i]+v[j])) continue;
					if(!check(vis, v, v[i]+v[k])) continue;
					if(!check(vis, v, v[k]+v[j])) continue;
					if(!check(vis, v, v[i]+v[j]+v[k])) continue;
					cout << v[i] << " " << v[j] << " " << v[k] << "\n";
					goto end;
				}
			}
		}
		end:
			continue;
	}
	return 0;
}
