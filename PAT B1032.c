#include <stdio.h>
#define maxn 100010


int main(void)
{
	int n,schId;
	int school[maxn] = {0};
	int score;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &schId, &score);
		school[schId] += score;
	}
	int id = 1, max = -1;
	for (int i = 0; i < n; ++i) {
		if (school[i] >= max) {
			max = school[i];
			id = i;
		}
	}
	printf("%d %d\n", id, max);
	return 0;
	}
