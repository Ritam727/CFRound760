#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define tests int t; cin >> t; while(t--)
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
using namespace std;

string binary(ll x) {
	string s;
	while(x > 0) {
		s = (char)(x%2+'0')+s;
		x /= 2;
	}
	return s;
}

bool check(string& a, string& b) {
	int al = a.length(), bl = b.length();
	for(int i = 0; i < bl-al+1; i++) {
		if(a == b.substr(i, al)) {
			bool f = true; int c = 0;
			for(int j = 0; j < i; j++) {
				if(b[j] == '0') {
					f = false;
					break;
				}
				c++;
			}
			for(int j = i+al; j < bl; j++) {
				if(b[j] == '0') {
					f = false;
					break;
				}
			}
			if(f) {
				if(a[al-1] == '0') {
					if(i+al < bl && b[i+al] == '1' && c > 0) {
						return true;
					} else if(c == 0) {
						return true;
					}
				} else {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll x, y; cin >> x >> y;
	string bx = binary(x), by = binary(y);
	int xl = bx.length(), yl = by.length();
	bool f1 = false, f2 = false, f3 = false, f4 = false;
	if(xl <= yl) {
		f1 = check(bx, by);
	}
	reverse(bx.begin(), bx.end());
	if(xl <= yl) {
		f2 = check(bx, by);
	}
	reverse(bx.begin(), bx.end());
	while(*bx.rbegin() == '0') bx.pop_back();
	xl = bx.length();
	if(xl <= yl) {
		f3 = check(bx, by);
	}
	reverse(bx.begin(), bx.end());
	if(xl <= yl) {
		f4 = check(bx, by);
	}
	if(f1 || f2 || f3 || f4) cout << "YES";
	else cout << "NO";
	return 0;
}
