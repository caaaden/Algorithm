#include <vector>
#include <random>
#include <algorithm>
using namespace std;

int kth(std::vector<int> &a, int k) {
	shuffle(a.begin(), a.end(), mt19937(random_device()()));
    nth_element(a.begin(), a.begin() + k - 1, a.end());
    return a[k - 1];
}
