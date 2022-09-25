#include <fstream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<ll> freqA, freqB, resX, resY;

int main() {
	ifstream cin(".\\watering_well_chapter_1_input.txt");
	ofstream cout(".\\watering_well_chapter_1_output.txt");

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int N; cin >> N;
		freqA.clear(); freqA.resize(3001, 0);
		freqB.clear(); freqB.resize(3001, 0);
		resX.clear(); resX.resize(3001, 0);
		resY.clear(); resY.resize(3001, 0);

		for (int i = 0; i < N; i++) {
			int A, B; cin >> A >> B;
			freqA[A]++; freqB[B]++;
		}

		for (int i = 0; i <= 3000; i++)
			for (int j = 0; j <= 3000; j++) {
				resX[i] = (resX[i] + freqA[j] * (j - i) * (j - i)) % mod;
				resY[i] = (resY[i] + freqB[j] * (j - i) * (j - i)) % mod;
			}

		int Q; cin >> Q;
		ll res = 0; while (Q--) {
			int X, Y; cin >> X >> Y;
			res = (res + resX[X] + resY[Y]) % mod;
		}

		cout << "Case #" << t << ": " << res << '\n';
	}
}