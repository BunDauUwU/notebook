/**
 * Author: Lukas Polacek, Joshua Andersson
 * Date: 2009-09-28
 * License: CC0
 * Source: folklore
 * Description: Operators for modular arithmetic. You need to set {\tt mod} to
 * some number first and then you can use the structure.
 */
#pragma once

#include "euclid.h"

template <ll MOD>
struct modnum {
    static constexpr bool big = MOD > numeric_limits<int>::max();

    using S = conditional_t<big, ll, int>;
    using L = conditional_t<big, __int128, ll>;

    S x;

    modnum(ll v = 0) {
        v %= MOD;
        x = v - MOD * (v < 0);
    }

    modnum pow(ll n) const {
        modnum res = 1, a = *this;
        for (; n; n >>= 1, a *= a)
            if (n & 1) res *= a;
        return res;
    }

    modnum inv() const {
        return pow(MOD - 2);
    }

    modnum& operator+=(const modnum& a) {
        if ((x += a.x) >= MOD) x -= MOD;   return *this;
    }

    modnum& operator-=(const modnum& a) {
        if ((x -= a.x) < 0) x += MOD;      return *this;
    }

    modnum& operator*=(const modnum& a) {
        x = static_cast<L>(x) * a.x % MOD; return *this;
    }

    modnum& operator/=(const modnum& a) {
        return *this *= a.inv();
    }

    friend modnum operator+(modnum a, const modnum& b) { return a += b; }
    friend modnum operator-(modnum a, const modnum& b) { return a -= b; }
    friend modnum operator*(modnum a, const modnum& b) { return a *= b; }
    friend modnum operator/(modnum a, const modnum& b) { return a /= b; }

    friend bool operator==(const modnum& a, const modnum& b) { return a.x == b.x; }
    friend bool operator!=(const modnum& a, const modnum& b) { return a.x != b.x; }
    friend bool operator<(const modnum& a, const modnum& b) { return a.x < b.x; }

    friend ostream& operator<<(ostream& os, const modnum& a) { return os << a.x; }
    friend istream& operator>>(istream& is, modnum& a) {
        ll v;
        is >> v;
        a = v;
        return is;
    }
};

using mint = modnum<MOD>;