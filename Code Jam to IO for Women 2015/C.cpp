#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define LL long long
#define N 9000
#define M 31684
vector<LL> v[N];
int re[M],cnt[N];

void multiFac() {
	for (int i = 1; i < N; i++) {
		for(int j = 9000; j > 1; j -= i) {
			int sz = v[i].size();
			if (sz == 0) {
				v[i].push_back(j);
				continue;
			}
			for (int k = 0; k < sz; k++) {
				v[i][k] = (LL)j*v[i][k];
			}
			for (int k = 0; k < sz; k++) {
				LL t = v[i][k] / (LL)1e9;
				v[i][k] = v[i][k] % (LL)1e9;
				if (t) {
					if (k + 1 == sz) {
						v[i].push_back(t);
					}
					else
						v[i][k + 1] += t;
				}
			}
		}
	}

	fill(re, re + M, 1e9);
	for (int i = 1; i < N; i++) {
		int tmp = 9 * (v[i].size() - 1);
		LL t = *(v[i].rbegin());
		for (LL j = 1; j <= t; j *= 10)
			tmp++;
		cnt[i] = tmp;
	}
	for (int i = 1; i < M; i++) {
		for (int j = 1; j < N; j++) {
			if (i > cnt[j]) {
				re[i] = j;
				break;
			}
		}

	}
}

void solve() {
	multiFac();
	int tc, tcn =0 , d;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &d);
		printf("Case #%d: ", ++tcn);
		if (d <= 4) {
			puts("...");
			continue;
		}
		printf("IT'S OVER 9000");
		int t;
		if (d < M)
			t = re[d];
		else
			t = 1;
		for (int j = 0; j < t; j++)
			printf("!");
		puts("");
	}
}

int main(void) {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	solve();
	return 0;
}