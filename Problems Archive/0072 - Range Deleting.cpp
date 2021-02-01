#include <iostream>
#include <vector>
using namespace std;

vector<int> seq, freq;
int n, x;

long long pair_count() {
	for (int i = 0; i < n; i++) { freq[seq[i]]++; }
}