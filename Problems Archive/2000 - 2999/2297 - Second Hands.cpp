#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> freq;

int main() {
	ifstream cin("second_hands_input.txt");
	ofstream cout("second_hands_output.txt");
	ios::sync_with_stdio(0);

	int T; cin >> T; 
	for(int t = 1; t <= T; t++) {
		int N, K; cin >> N >> K;
		freq.clear(); freq.resize(100);
		for (int i = 0; i < N; i++) {
			int x; cin >> x; freq[--x]++;
		}

		int maxOcc = *max_element(freq.begin(), freq.end());
		bool ok = maxOcc < 3 && N <= K << 1;
		cout << "Case #" << t << ": " << (ok ? "YES" : "NO") << '\n';
	}
}