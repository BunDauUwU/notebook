/**
 * Author: lumie
 * Description: Fast C++ contest template and common helpers.
 */
#include <bits/stdc++.h>

using namespace std;

#define el  '\n'
#define fi  first
#define se  second
#define pb  push_back
#define all(v)  (v).begin(), (v).end()
#define sz(x)  (int)(x).size()
#define rep(i, a, b)  for(int i = a; i < (b); ++i)

using ll  = long long;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = vector<int>;
using vll = vector<ll>;

constexpr ll MOD = 1e9 + 7;
constexpr ll oo  = 1e18;

template <class T, class U>
inline void add(T &a, U b) {
	a = (a + b) % MOD;
	if (a < 0) a += MOD;
}

template<class T, class U>
inline void mul(T &a, U b) {
	a = (ll)((__int128)a * b % MOD);
	if (a < 0) a += MOD;
}

template <class T, class U>
inline bool ckmin(T &a, U b) {
	return a > b ? a = b, 1 : 0;
}

template <class T, class U>
inline bool ckmax(T &a, U b) {
	return a < b ? a = b, 1 : 0;
}

constexpr int N = 2e5 + 5;
constexpr int M = 2e5 + 5;
constexpr int K = 2e5 + 5;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	return 0;
}
