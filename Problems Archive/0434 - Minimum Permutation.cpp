#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M; cin >> N >> M;
	vector<int> A(N), S(M);
	for (auto &x : A) { cin >> x; }
	for (auto &x : S) { cin >> x; }
	sort(S.begin(), S.end());
	int i = 0, j = 0;
	while (i < N && j < M) {
		if (S[j] <= A[i]) { cout << S[j] << " "; j++; }
		else { cout << A[i] << " "; i++; }
	}
	while (i < N) { cout << A[i] << " "; i++; }
	while (j < M) { cout << S[j] << " "; j++; }
	return 0;
}