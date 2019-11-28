package main

import "fmt"

func less(ucet []int, K int) uint64 {
	pref := make([]int, len(ucet))
	var sum uint64
	for i, d := range ucet {
		if i > 0 {
			pref[i] = pref[i-1] + d
		} else {
			pref[i] = d
		}
	}
	for i := 0; i < len(pref); i++ {
		if pref[i] < K {
			sum++
		}
		for j := 0; j < i; j++ {
			if pref[i]-pref[j] < K {
				sum++
			}
		}
	}
	return sum
}

func main() {
	var T int
	fmt.Scanf("%d", &T)
	for ; T > 0; T-- {
		println(T)
		var N, K int
		fmt.Scanf("%d%d", &N, &K)
		ucet := make([]int, N)
		for i := 0; i < N; i++ {
			fmt.Scanf("%d", &ucet[i])
		}
		fmt.Printf("%d\n", less(ucet, K))
	}
}
