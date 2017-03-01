#include <cstdio>
#define LL long long 
#define N 25
LL d[27][27];
int tc, tcn,r, c,re;

void solve() {
	for (int i = 1; i <= N; i++)
		d[i][1] = d[1][i] = 1; 
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			for (int k = 1; k <= i; k++)
				d[i][j] += d[k][j - 1];
		}
	}

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &r, &c);

		printf("Case #%d: %lld\n", ++tcn, d[r][c]);
	}
}

int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();
	return 0;
}