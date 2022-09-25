#include <fstream>
#include <string>
#include <vector>
using namespace std;

ifstream cin("second_second_meaning_input.txt");
ofstream cout("second_second_meaning_output.txt");
string S; vector<bool> B; int K;

bool isPrefix(int M) {
	for (int i = 0; i < K && (1 << i) <= M; i++)
		if (B[i] ^ ((M & (1 << i)) != 0)) return false;
	return true;
}

void print(int i) {
	int cur = 1; while (cur <= i) {
		cout << (cur & i ? '-' : '.'); cur <<= 1;
	}
	cout << '\n';
}

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int N; cin >> N >> S; K = (int)S.size(); B.resize(K);
		for (int i = 0; i < K; i++) B[i] = S[i] == '-';

		cout << "Case #" << t << ": \n";
		int rem = N - 1; for (int i = 1023; i >= 0 && rem; i--)
			if (!isPrefix(i)) { print(i); rem--; }
	}
}