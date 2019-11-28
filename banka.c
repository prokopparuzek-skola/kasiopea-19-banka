#include <stdio.h>
#include <stdlib.h>

unsigned long long less(int *ucet, int K, int N) {
    int *pref = malloc(N*sizeof(int));
    unsigned long long sum = 0;
	for (int i = 0; i < N; i++) {
		if (i > 0) {
			pref[i] = pref[i-1] + ucet[i];
		} else {
			pref[i] = ucet[i];
		}
	}
	for (int i = 0; i < N; i++) {
		if (pref[i] < K) {
			sum++;
		}
		for (int j = 0; j < i; j++) {
			if (pref[i]-pref[j] < K) {
				sum++;
			}
		}
	}
    free(pref);
    return sum;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        fprintf(stderr, "%d\n", i);
        int N, K;
        scanf("%d%d", &N, &K);
        int *ucet = malloc(N*sizeof(int));
        for (int j = 0; j < N; j++) {
            scanf("%d", ucet+j);
        }
        printf("%llu\n", less(ucet, K, N));
        free(ucet);
    }
    return 0;
}
