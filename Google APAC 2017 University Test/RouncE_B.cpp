#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long
int tc, tcn;
LL n,re;

LL get(int num, LL n) {
	if ((int)(log(n)/log(2)+1e-9) < num-1)
		return -1;
	LL le = 2, ri = n, mid, ret= -1;
	while (le <= ri) {
		LL mid = (le + ri) / 2;
		if ((int)(log(n) / log(mid)+1e-9) < num-1) {
			ri = mid - 1;
			continue;
		}
		LL sum = 0;
		for (LL j = 0, t = 1; j < (LL)num; j++,t*=mid) {
			sum += t;
		}
		if (sum <= n) {
			le = mid + 1;
			if (sum == n) {
				return mid;
			}
		}
		else {
			ri = mid - 1;
		}
	}

	return -1;
}

void solve() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%lld", &n);
		re = n - 1;
		for (int i = 64; i >= 2; i--) {
			LL ret = get(i,n);
			if (ret > 0) {
				re = ret;
				break;
			}
		}
		printf("Case #%d: %lld\n", ++tcn, re);
	}
}

int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();
	return 0;
}