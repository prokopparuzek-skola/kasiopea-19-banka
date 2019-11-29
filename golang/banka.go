package main

import "fmt"

func less(ucet []int, K int, task chan uint64) {
	println(ucet)
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
	println("OK")
	task <- sum
}

func main() {
	var T int
	fmt.Scanf("%d", &T)
	tasks := make([]chan uint64, T)
	for i := range tasks {
		tasks[i] = make(chan uint64)
	}
	for i := 0; i < T; i++ {
		println(i)
		var N, K int
		fmt.Scanf("%d%d", &N, &K)
		ucet := make([]int, N)
		for j := 0; j < N; j++ {
			fmt.Scanf("%d", &ucet[j])
		}
		go less(ucet, K, tasks[i])
	}
	for i := 0; i < T; i++ {
		fmt.Printf("%d\n", <-tasks[i])
	}
}
