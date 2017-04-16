#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int tc, tcn, n,m;
char s[25][29];

bool isExist(char c, int le, int ri, int low, int up) {
	for (int i = low; i <= up; i++) {
		for (int j = le; j <= ri; j++) {
			if (s[i][j] == c)
				return true;
		}
	}
	return false;
}

void fillCake(int le, int ri, int low, int up) {
	char c;
	for (int i = low; i <= up; i++) {
		for (int j = le; j <= ri; j++) 
			if (s[i][j] != '?')
				c = s[i][j];
	}
	for (int i = low; i <= up; i++) {
		for (int j = le; j <= ri; j++)
			s[i][j] = c;
	}
}
void divideNconquer(int le, int ri, int low, int up) {
	bool ch[26];
	
	if (le == ri || low == up) {
		memset(ch, 0, sizeof(ch));
		int cnt = 0;
		for (int i = low; i <= up; i++) {
			for (int j = le; j <= ri; j++) {
				if (s[i][j]!= '?' && !ch[s[i][j] - 'A']) {
					ch[s[i][j] - 'A'] = 1;
					cnt++;
				}
			}
		}
		if (cnt == 1) {
			fillCake(le, ri, low, up);
			return;
		}
	}

	for (int i = le+1; i <= ri; i++) {
		bool pos = 1;
		int l = 0, r = 0;
		memset(ch, 0, sizeof(ch));
		for (int k = low; k <= up && pos; k++) {
			for (int j = le; j < i && pos; j++) {
				if (s[k][j] != '?' && !ch[s[k][j]-'A']) {
					pos &= (1 ^ isExist(s[k][j], i, ri, low, up));
					l++;
					ch[s[k][j] - 'A'] = 1;
					
				}
			}
			for (int j = i; j <= ri && pos; j++) {
				if (s[k][j] != '?' && !ch[s[k][j]-'A']) {
					pos &= (1 ^ isExist(s[k][j], le, i - 1, low, up));
					r++;
					ch[s[k][j] - 'A'] = 1;
				}
			}
		}
		if (l + r == 1) {
			fillCake(le, ri, low, up);
			return;
		}
		if (pos && r && l) {
			divideNconquer(le, i - 1, low, up);
			divideNconquer(i, ri, low, up);
			return;
		}
	}

	for (int i = low+1; i <= up; i++) {
		memset(ch, 0, sizeof(ch));
		bool pos = 1;
		int l = 0, u = 0;
		for (int j = low; j < i && pos; j++) {
			for (int k = le; k <= ri && pos; k++) {
				if (s[j][k] != '?' && !ch[s[j][k]-'A']) {
					ch[s[j][k] - 'A'];
					l++;
					pos &= (1 ^ isExist(s[j][k], le, ri, i, up));
				}
			}
		}
		for (int j = i; j <= up && pos; j++) {
			for (int k = le; k <= ri && pos; k++) {
				if (s[j][k] != '?' && !ch[s[j][k] - 'A']) {
					ch[s[j][k] - 'A'];
					u++;
					pos &= (1 ^ isExist(s[j][k], le, ri, low,i-1));
				}
			}
		}
		if (l + u == 1) {
			fillCake(le, ri, low, up);
			return;
		}
		if (pos && l && u) {
			divideNconquer(le, ri, low, i-1);
			divideNconquer(le, ri, i, up);
			return;
		}
	}
}

void solve() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%s", s[i]);
		divideNconquer(0, m - 1, 0, n - 1);
		printf("Case #%d:\n", ++tcn);
		for (int i = 0; i < n; i++) {
			printf("%s\n", s[i]);
		}
	}
}

int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();
	return 0;
}