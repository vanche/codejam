#include <cstdio>
int tc,tcn, n;
char s[8008];

void solve() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %s",&n,s);
		printf("Case #%d: ", ++tcn);
		for (int i = 0; i < 8*n; i+=8) {
			char a = 0;
			for (int j = 0; j < 8; j++) {
				a <<= 1;
				if (s[i + j] == 'I')
					a += 1;
			}
			printf("%c", a);
		}
		puts("");
	}
}

int main(void) {
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}