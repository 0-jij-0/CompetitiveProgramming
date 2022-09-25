#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<ll> A, B, X, Y; int N, Q;

ll findSum(vector<ll>& V, vector<ll>& P) {
	ll res = 0, cur = 0, prev = 0, XB = 0, FX = 0; 
	for (int i = 0; i < N; i++) { 
		cur = (cur + V[i] * V[i]) % mod;
		FX = (FX + V[i]) % mod;
	}

	int b = 0, f = N;
	auto shift = [&](const ll& S) {
		ll SS = (S * S) % mod;
		ll SXB = (2 * S * XB) % mod, SFX = (2 * S * FX) % mod;
		cur = (cur + N * SS + SXB - SFX + mod) % mod;
		XB = (XB + S * b) % mod; FX = (FX - ((S * f) % mod) + mod) % mod;
	};

	
	for (int i = 0, j = 0; i < Q; i++) {
		while (j < N && V[j] <= P[i]) {
			shift(V[j] - prev); 
			prev = V[j++]; b++; f--;
		}
		shift(P[i] - prev); prev = P[i];
		res = (res + cur) % mod;
	}

	return res;
}

int main() {
	ifstream cin(".\\watering_well_chapter_2_input.txt");
	ofstream cout(".\\watering_well_chapter_2_output.txt");

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N; A.resize(N); B.resize(N);
		for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
		sort(A.begin(), A.end()); sort(B.begin(), B.end());

		cin >> Q; X.resize(Q); Y.resize(Q);
		for (int i = 0; i < Q; i++) cin >> X[i] >> Y[i];
		sort(X.begin(), X.end()); sort(Y.begin(), Y.end());
		
		ll res = (findSum(A, X) + findSum(B, Y)) % mod;
		cout << "Case #" << t << ": " << res << '\n';
	}
}