#include <algorithm>
#include <bit>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

int n;
vi xs;
ll m;

bool check(ll val) {
	auto sum = ll{ 0 };
	for (const auto& x : xs) {
		if (x <= val) {
			sum += x;
		}
		else {
			sum += val;
		}
	}

	//cout << "sum = " << sum << endl;
	return sum <= m;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;

	xs = vi(n);
	ll total = 0;
	for (auto&& x : xs) {
		cin >> x;
		total += x;
	}

	cin >> m;

	if (total <= m) {
		cout << *max_element(xs.begin(), xs.end());
		return 0;
	}

	ll l = 0;
	ll r = m;
	while (l <= r) {
		auto mid = (l + r) / 2;
		//cout << l << ' ' << r << ' ' << mid << '\n';

		if (check(mid)) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << l - 1;

	return 0;
}