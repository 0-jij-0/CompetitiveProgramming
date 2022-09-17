#include <iostream>
#include <string>
using namespace std;

int query(int A, int B, int C = 0, int D = 0) {
	if (!C) { cout << "! " + to_string(A) + " " + to_string(B) << endl; return 0; }
	cout << "? " + to_string(A) + " " + to_string(B) + " " + to_string(C) + " " + to_string(D) << endl;

	int x; cin >> x; return x;
}

int main() {
	int N; cin >> N;

	int L = 1, R = N; while (L != R) {
		int mid = (L + R) >> 1;
		int x = query(L, mid, 1, N);
		x == (mid - L) ? R = mid : L = mid + 1;
	}

	int X = L; L = 1, R = N; while (L != R) {
		int mid = (L + R) >> 1;
		int x = query(1, N, L, mid);
		x == (mid - L) ? R = mid : L = mid + 1;
	}

	query(X, L);
}