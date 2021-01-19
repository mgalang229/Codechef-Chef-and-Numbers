#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		// create a prev variable to check for adjacent elements
		int prev = INT_MIN;
		// create a max_size variable to store the largest element (size of counter vector)
		int max_size = 0;
		vector<int> no_adjacent;
		for (int i = 0; i < n; i++) {
			// check if the current element is equal to the previous element
			if (v[i] != prev) {
				// store every number in max_size to get the largest value
				max_size = max(max_size, v[i]);
				// add it in the new vector
				no_adjacent.emplace_back(v[i]);
				// store the element to be used for comparison in the next element
				prev = v[i];
			} else {
				// otherwise, reset prev back to 0
				prev = 0;
			}
		}
		// count the number of frequencies of every element from the no_adjacent vector
		vector<int> counter(max_size + 1, 0);
		for (auto x : no_adjacent) {
			counter[x]++;
		}
		// find the largest frequency of an element
		int max_frequency = 0;
		for (int i = 1; i < (int) counter.size(); i++) {
			max_frequency = max(max_frequency, counter[i]);
		}
		// since this is already sorted, we do not need to get the minimum element
		// break the loop once the if condition is true (that is the smallest element)
		// check if the frequency of an element is equal to the frequency of the number being checked
		for (int i = 1; i < (int) counter.size(); i++) {
			if (counter[i] == max_frequency) {
				cout << i << '\n';
				break;
			}
		}
	}
	return 0; 
}
