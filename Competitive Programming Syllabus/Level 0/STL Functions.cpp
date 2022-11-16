#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void testSTLFunctions(vector<int>& V) {
	int N = (int)V.size();

	///////////////////////////////////////////////////////////////////////////

	/* Sum --> accumulate */
	cout << "Sum:\n";
	ll sum = 0; for (auto& x : V) sum += x;
	cout << sum << '\n';

	//OR Using STL
	sum = accumulate(V.begin(), V.end(), 0ll);
	cout << sum << "\n\n";

	///////////////////////////////////////////////////////////////////////////

	/* Reverse --> reverse */
	cout << "Reverse:\n"; 
	vector<int> VR1 = V;
	int i = 0, j = N - 1;
	while (i < j) swap(VR1[i++], VR1[j--]);
	for (auto& x : VR1) cout << x << ' '; cout << '\n';

	//OR Using STL
	vector<int> VR2(V.begin(), V.end());
	reverse(VR2.begin(), VR2.end());
	for (auto& x : VR2) cout << x << ' '; cout << "\n\n";

	///////////////////////////////////////////////////////////////////////////

	/* Sort Increasing --> sort */
	//Using STL
	cout << "Sorted Increasing:\n";
	vector<int> sortedV(V.begin(), V.end());
	sort(sortedV.begin(), sortedV.end());
	for (auto& x : sortedV) cout << x << ' '; cout << "\n\n";

	///////////////////////////////////////////////////////////////////////////

	/* Sort Decreasing --> sort */
	//Using STL
	cout << "Sorted Decreasing:\n";
	vector<int> revSortedV1(V.begin(), V.end());
	sort(revSortedV1.begin(), revSortedV1.end());
	reverse(revSortedV1.begin(), revSortedV1.end());
	for (auto& x : revSortedV1) cout << x << ' '; cout << "\n\n";

	//Even better using STL
	vector<int> revSortedV2(V.begin(), V.end());
	sort(revSortedV2.rbegin(), revSortedV2.rend());
	for (auto& x : revSortedV2) cout << x << ' '; cout << "\n\n";

	///////////////////////////////////////////////////////////////////////////

	/* Unique Elements --> sort + unique OR set */
	//Using STL
	cout << "Unique Elements:\n";
	vector<int> uniqueV1 = V;
	sort(uniqueV1.begin(), uniqueV1.end());
	uniqueV1.erase(unique(uniqueV1.begin(), uniqueV1.end()), uniqueV1.end());
	for (auto& x : uniqueV1) cout << x << ' '; cout << '\n';

	//Or also using STL
	set<int> uniqueV2(V.begin(), V.end());
	for (auto& x : uniqueV2) cout << x << ' '; cout << "\n\n";

	///////////////////////////////////////////////////////////////////////////

	/* Prefix Sum --> partial_sum */
	cout << "Prefix Sum:\n";
	vector<ll> prefSum1(N); prefSum1[0] = V[0];
	for (int i = 1; i < N; i++) prefSum1[i] = V[i] + prefSum1[i - 1];
	for (auto& x : prefSum1) cout << x << ' '; cout << '\n';

	//Or Using STL
	vector<ll> prefSum2(N);
	partial_sum(V.begin(), V.end(), prefSum2.begin());
	for (auto& x : prefSum2) cout << x << ' '; cout << "\n\n";

	///////////////////////////////////////////////////////////////////////////

	/* Suffix Sum --> partial_sum */
	cout << "Suffix Sum:\n";
	vector<ll> suffSum1(N); suffSum1[N - 1] = V[N - 1];
	for (int i = N - 2; i >= 0; i--) suffSum1[i] = V[i] + suffSum1[i + 1];
	for (auto& x : suffSum1) cout << x << ' '; cout << '\n';

	//OR Using STL
	vector<ll> suffSum2(N);
	vector<int> revV(V.rbegin(), V.rend());
	partial_sum(revV.begin(), revV.end(), suffSum2.begin());
	reverse(suffSum2.begin(), suffSum2.end());
	for (auto& x : suffSum2) cout << x << ' '; cout << '\n';

	//Even better Using STL
	vector<ll> suffSum3(N);
	partial_sum(V.rbegin(), V.rend(), suffSum3.rbegin());
	for (auto& x : suffSum3) cout << x << ' '; cout << "\n\n";

	///////////////////////////////////////////////////////////////////////////

	/* Count elements --> count */
	cout << "Count of elements equal to the first element:\n";
	int firstElementCount1 = 0;
	for (auto& x : V) firstElementCount1 += x == V.front();
	cout << firstElementCount1 << '\n';

	//OR Using STL
	int firstElementCount2 = count(V.begin(), V.end(), V.front());
	cout << firstElementCount2 << "\n\n";

	///////////////////////////////////////////////////////////////////////////

	/* Left Rotation --> rotate */
	//Using STL
	cout << "1 Cyclic Left Rotation:\n";
	vector<int> leftRotatedV = V;
	rotate(leftRotatedV.begin(), leftRotatedV.begin() + 1, leftRotatedV.end());
	for (auto& x : leftRotatedV) cout << x << ' '; cout << "\n\n";

	///////////////////////////////////////////////////////////////////////////

	/* Right Rotation --> rotate */
	//Using STL
	cout << "1 Cyclic Right Rotation:\n";
	vector<int> rightRotatedV = V;
	rotate(rightRotatedV.rbegin(), rightRotatedV.rbegin() + 1, rightRotatedV.rend());
	for (auto& x : rightRotatedV) cout << x << ' '; cout << "\n\n";

	///////////////////////////////////////////////////////////////////////////

	/* Minimum --> min_element */
	cout << "Minimum element:\n";
	int minIDX1 = 0;
	for (int i = 0; i < N; i++)
		if (V[i] < V[minIDX1]) minIDX1 = i;
	cout << "V[" << minIDX1 << "] = " << V[minIDX1] << '\n';

	//OR Using STL
	auto minIDX2 = min_element(V.begin(), V.end());
	cout << "V[" << minIDX2 - V.begin() << "] = " << *minIDX2 << "\n\n";

	///////////////////////////////////////////////////////////////////////////

	/* Maximum --> max_element */
	cout << "Maximum element:\n";
	int maxIDX1 = 0;
	for (int i = 0; i < N; i++)
		if (V[i] > V[maxIDX1]) maxIDX1 = i;
	cout << "V[" << maxIDX1 << "] = " << V[maxIDX1] << '\n';

	//OR Using STL
	auto maxIDX2 = max_element(V.begin(), V.end());
	cout << "V[" << maxIDX2 - V.begin() << "] = " << *maxIDX2 << "\n\n";

	///////////////////////////////////////////////////////////////////////////

	/* Median --> sort OR nth_element */
	cout << "Median Element:\n";

	//Using STL
	vector<int> medianV1 = V;
	sort(medianV1.begin(), medianV1.end());
	cout << medianV1[N >> 1] << '\n';

	//Even better using STL
	vector<int> medianV2(V.begin(), V.end());
	nth_element(medianV2.begin(), medianV2.begin() + (N >> 1), medianV2.end());
	cout << medianV2[N >> 1] << "\n\n";

	///////////////////////////////////////////////////////////////////////////

	//Check other functions using C++ documentation: https://en.cppreference.com/
	//find, find_if, count_if, for_each, fill, partition, merge, stable_sort
	//HEAP OPERATIONS, minmax_element, next_permutation, binary_search, ...

	//Also check all sorts of magic you can do by using lambda functions in STL functions!
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin.tie(0)->sync_with_stdio(0);

	vector<int> V(7); int f = 0;
	//Fills V with f, f + 1, f + 2, ..., f + N - 1
	iota(V.begin(), V.end(), f);

	//Inserting some duplicates
	for (int i = 0; i < 3; i++)
		V.push_back(rand() % 7);

	//Randomly shuffles array V
	shuffle(V.begin(), V.end(), rng);

	cout << "V = "; for (auto& x : V) 
		cout << x << ' '; cout << "\n\n";

	testSTLFunctions(V);
}