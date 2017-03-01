#include <cstdio>
int tc, tcn;
long long v, k,re;

void solve() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%lld %lld", &k, &v);
	

		if (v < k) {
			re = k + 1;
			if (v) {
				re += (k - v + 1)*v * 6;
				re += 3 *v*(v - 1);
				if (v >= 2) {
					re += 3*(k - v + 1)*v*(v - 1);
					for (int j = 1; j < v - 1; j++)
						re += 3*(v - j)*(v - j - 1);
				}
			}
		}
		else {
			re = (k + 1)*(k + 1)*(k + 1);
		}
		printf("Case #%d: %lld\n", ++tcn, re);
	}
}

int main(void) {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}