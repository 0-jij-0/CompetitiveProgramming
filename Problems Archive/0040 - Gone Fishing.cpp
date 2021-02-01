#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> fishes;
vector<int> dec_rate;
vector<int> time_next;

void input(int &n) {
	fishes.resize(n); dec_rate.resize(n); time_next.resize(n - 1);
	for (int i = 0; i < n; i++) { cin >> fishes[i]; }
	for (int i = 0; i < n; i++) { cin >> dec_rate[i]; }
	for (int i = 0; i < n - 1; i++) { cin >> time_next[i]; }
}