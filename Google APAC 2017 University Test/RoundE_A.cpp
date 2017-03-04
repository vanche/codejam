#include <cstdio>
#include <cstring>
#define LL long long
int tc, tcn;
LL l, r;
char s[111];

LL get(LL num,int cnt) {
	if (!num) return 0;
	LL len = strlen(s);
	LL ret = num / len*cnt;
	for (LL i = 0; i < num%len; i++)
		if(s[i] == 'B')
			ret++;
	return ret;
}
void solve() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%s %lld %lld", s, &l, &r);
		LL cnt, re,len = strlen(s);
		re = cnt = 0;
		for (int i = 0; i < len; i++)
			if (s[i] == 'B') cnt++;
		re = get(r, cnt) - get(l - 1, cnt);

		printf("Case #%d: %lld\n", ++tcn, re);
	}
}

int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();
	return 0;
}