#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A, B; int N;

bool eqVectors() {
	for (int i = 0; i < N; i++)
		if (A[i] != B[i]) return false;
	return true;
}

int main() {
	ifstream cin(".\\consecutive_cuts_chapter_1_input.txt");
	ofstream cout(".\\consecutive_cuts_chapter_1_output.txt");

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int K; cin >> N >> K;
		A.resize(N); for (auto& x : A) cin >> x;
		B.resize(N); for (auto& x : B) cin >> x;

		cout << "Case #" << t << ": ";
		auto it = find(A.begin(), A.end(), B.front());
		bool b = (it != A.begin());

		rotate(A.begin(), it, A.end());
		if (!eqVectors()) { cout << "NO\n"; continue; }

		bool cant = (K == 0 && b) || (K == 1 && !b) || (N == 2 && ((K & 1) ^ b));
		cout << (cant ? "NO" : "YES") << '\n';
	}
}