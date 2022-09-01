#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

int main() {
	freopen("ronaldo.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T; while (T--) {
		int N, M; cin >> N >> M;
		multiset<int> barca, madrid; ll bSum = 0, mSum = 0;
		while (N--) { int x; cin >> x; bSum += x; barca.insert(x); }
		while (M--) { int x; cin >> x; mSum += x; madrid.insert(x); }

		int res = 0; while (bSum < mSum) {
			auto bSmall = barca.begin(), mLarge = --madrid.end();
			if (*bSmall >= *mLarge) { break; }

			bSum += *mLarge - *bSmall; mSum += *bSmall - *mLarge;
			barca.insert(*mLarge); madrid.insert(*bSmall);
			barca.erase(bSmall); madrid.erase(mLarge); res++;
		}

		cout << (bSum < mSum ? -1 : (res + 2) / 3) << '\n';
	}
}