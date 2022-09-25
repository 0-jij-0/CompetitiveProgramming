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

vector<int> prefixFunction(vector<int>& s) {
	vector<int> pf(s.size(), 0);
	for (int i = 1; i < (int)s.size(); i++) {
		int j = pf[i - 1];
		while (j > 0 && s[j] != s[i]) { j = pf[j - 1]; }
		if (s[j] == s[i]) { j++; }
		pf[i] = j;
	}
	return pf;
}

int stringMatch(vector<int>& s, vector<int>& p) {
	vector<int> temp = p; temp.push_back(0); 
	temp.insert(temp.end(), s.begin(), s.end());
	vector<int> pf = prefixFunction(temp);

	return count(pf.begin() + p.size() + 1, pf.end(), p.size());
}

int main() {
	ifstream cin(".\\consecutive_cuts_chapter_2_input.txt");
	ofstream cout(".\\consecutive_cuts_chapter_2_output.txt");

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int K; cin >> N >> K;
		A.resize(N); for (auto& x : A) cin >> x;
		B.resize(N); for (auto& x : B) cin >> x;

		cout << "Case #" << t << ": ";
		if (K == 0) { cout << (eqVectors() ? "YES" : "NO") << '\n'; continue; }
		if (N == 2) {
			if (K & 1) { reverse(A.begin(), A.end()); }
			cout << (eqVectors() ? "YES" : "NO") << '\n'; continue;
		}

		A.resize((N << 1) - 1);
		for (int i = 0; i < N - 1; i++) A[i + N] = A[i];
		if (K == 1) { A.erase(A.begin()); }
		int match = stringMatch(A, B);

		cout << (match ? "YES" : "NO") << '\n';
	}
}