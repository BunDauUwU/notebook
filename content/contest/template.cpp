#include <bits/stdc++.h>

using namespace std;

#define el  '\n'
#define fi  first
#define se  second
#define pb  push_back
#define Elaina  signed main()
#define ALL(v)  (v).begin(), (v).end()
#define sz(x)  (int)(x).size()
#define rep(i, a, b)  for(int i = a; i < (b); ++i)

using ll  = long long;
using ld  = long double;
using pii = pair<ll, ll>;
using ull = unsigned long long;

constexpr ll MOD = 1e9 + 7;
constexpr ll oo  = 1e18;

template <class T, class U>
inline void add(T &a, U b) {
    a += b;
    a += MOD * (a < 0) - MOD * (a >= (ll)MOD);
}

template<class T, class U>
inline void mul(T &a, U b) {
    a = a * b - MOD * ull(1.L / MOD * a * b);
    a += MOD * (a < 0) - MOD * (a >= (ll)MOD);
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

Elaina {

}