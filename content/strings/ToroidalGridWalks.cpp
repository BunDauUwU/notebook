/**
 * Author: lumie
 * Description: Counts equal length-k strings obtained by starting in every
 * grid cell and walking in each of the eight directions on a toroidal grid.
 * Prints the probability that two uniformly chosen walks are equal.
 * Time: O(8NM log K)
 * Memory: O(NM log K)
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = uint32_t;
using u64 = uint64_t;

constexpr int BASE[] = {127, 3137};
constexpr int HMOD[] = {1000000007, 999999937};

struct Hash {
	u32 a = 0, b = 0;

	Hash() = default;
	Hash(unsigned char c) : a(c), b(c) {}

	void append(const Hash& other, int lg,
	            const vector<u32>& powA,
	            const vector<u32>& powB) {
		a = u32((u64(a) * powA[lg] + other.a) % HMOD[0]);
		b = u32((u64(b) * powB[lg] + other.b) % HMOD[1]);
	}

	u64 key() const { return u64(b) << 32 | a; }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	unsigned k;
	if (!(cin >> n >> m >> k)) return 0;
	vector<string> grid(n);
	for (string& row : grid) cin >> row;

	int levels = 1;
	while (levels < 32 && (1U << levels) <= k) ++levels;
	vector<u32> powA(levels), powB(levels);
	powA[0] = BASE[0];
	powB[0] = BASE[1];
	for (int lg = 1; lg < levels; ++lg) {
		powA[lg] = u32(u64(powA[lg - 1]) * powA[lg - 1]
		                 % HMOD[0]);
		powB[lg] = u32(u64(powB[lg - 1]) * powB[lg - 1]
		                 % HMOD[1]);
	}

	vector<int> stepN(levels), stepM(levels);
	stepN[0] = 1 % n;
	stepM[0] = 1 % m;
	for (int lg = 1; lg < levels; ++lg) {
		stepN[lg] = stepN[lg - 1] * 2 % n;
		stepM[lg] = stepM[lg - 1] * 2 % m;
	}

	vector table(levels, vector(n, vector<Hash>(m)));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			table[0][i][j] = Hash(grid[i][j]);

	unordered_map<u64, ull> frequency;
	frequency.reserve(size_t(n) * m * 8);
	for (int dx = -1; dx <= 1; ++dx) {
		for (int dy = -1; dy <= 1; ++dy) {
			if (dx == 0 && dy == 0) continue;
			vector<int> sx(levels), sy(levels);
			for (int lg = 0; lg < levels; ++lg) {
				sx[lg] = int(ll((dx % n + n) % n)
				             * stepN[lg] % n);
				sy[lg] = int(ll((dy % m + m) % m)
				             * stepM[lg] % m);
			}

			for (int lg = 1; lg < levels; ++lg)
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < m; ++j) {
						int x = (i + sx[lg - 1]) % n;
						int y = (j + sy[lg - 1]) % m;
						table[lg][i][j] = table[lg - 1][i][j];
						table[lg][i][j].append(
						    table[lg - 1][x][y], lg - 1,
						    powA, powB);
					}

			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j) {
					Hash hash;
					int x = i, y = j;
					for (int lg = 0; lg < levels; ++lg) {
						if (!(k >> lg & 1U)) continue;
						hash.append(table[lg][x][y], lg,
						            powA, powB);
						x = (x + sx[lg]) % n;
						y = (y + sy[lg]) % m;
					}
					++frequency[hash.key()];
				}
		}
	}

	ull numerator = 0;
	for (auto [hash, count] : frequency)
		numerator += count * count;
	ull walks = ull(n) * m * 8;
	ull denominator = walks * walks;
	ull divisor = gcd(numerator, denominator);
	cout << numerator / divisor << '/' << denominator / divisor << '\n';
}
