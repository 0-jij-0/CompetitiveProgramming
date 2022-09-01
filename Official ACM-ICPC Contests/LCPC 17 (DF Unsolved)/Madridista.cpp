#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> A;

bool checkDivision(int P, int K) {
	int res = 0, N = (int)A.size();
	for (int i = 0; i < P; i++) {
		map<int, int> freq;
		for (int j = i; j < N; j += P) freq[A[j]]++;
		int ans = 0; for (auto& x : freq) ans = max(ans, x.second);
		res += N / P - ans;
	}
	return res <= K;
}

int main() {
	freopen("madridista.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T; while (T--) {
		int N, K; cin >> N >> K; A.resize(N);
		for (auto& x : A) cin >> x;

		int P = 0;
		for (int i = 1; i * i <= N; i++) if (N % i == 0) {
			if (checkDivision(i, K)) { P = i; break; }
			if (checkDivision(N / i, K)) { P = N / i; }
		}

		cout << P << '\n';
		for (int i = 0; i < P; i++) {
			map<int, int> freq;
			for (int j = i; j < N; j += P) freq[A[j]]++;
			int ans = freq[A[i]]; for (auto& x : freq)
				if (x.second > freq[ans]) ans = x.first;
			for (int j = i; j < N; j += P) A[j] = ans;
		}
		for (auto& x : A) cout << x << ' '; cout << '\n';
	}
}