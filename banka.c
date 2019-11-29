#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
	int *ucet;
	int K;
	int N;
    unsigned long long ret;
} vstup;

void* less(void *i) {
	vstup *in = (vstup*)i;
    long long int *pref = malloc(in->N*sizeof(long long int));
    unsigned long long sum = 0;
	for (int i = 0; i < in->N; i++) {
		if (i > 0) {
			pref[i] = pref[i-1] + in->ucet[i];
		} else {
			pref[i] = in->ucet[i];
		}
	}
	for (int i = 0; i < in->N; i++) {
		if (pref[i] < in->K) {
			sum++;
		}
		for (int j = 0; j < i; j++) {
			if (pref[i]-pref[j] < in->K) {
				sum++;
			}
		}
	}
    free(pref);
	free(in->ucet);
    in->ret = sum;
    fprintf(stderr, "OK\n");
    return NULL;
}

int main() {
    int T;
    pthread_t *vlakna;
	vstup *vstupy;
    scanf("%d", &T);
	vstupy = malloc(T*sizeof(vstup));
    vlakna = malloc(T*sizeof(pthread_t));
    for (int i = 0; i < T; i++) {
        fprintf(stderr, "%d\n", i);
        int N, K;
        scanf("%d%d", &N, &K);
        int *ucet = malloc(N*sizeof(int));
        for (int j = 0; j < N; j++) {
            scanf("%d", ucet+j);
        }
		vstupy[i].K = K;
		vstupy[i].N = N;
		vstupy[i].ucet = ucet;
        pthread_create(vlakna+i, NULL, less, (void *) &vstupy[i]);
    }
    for (int i = 0; i < T; i++) {
        pthread_join(vlakna[i], NULL);
        printf("%llu\n", vstupy[i].ret);
    }
	free(vstupy);
    free(vlakna);
    return 0;
}
