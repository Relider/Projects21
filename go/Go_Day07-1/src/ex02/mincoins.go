// This package provides functions for calculating the minimum amount of coins required to buy something.
package mincoins

import "slices"

// minCoins v2. Some corner cases are addressed:
// 1) If the coins slice is not sorted;
// 2) If there are values < 1 in the coins slice;
// 3) If you can't spend all your money with the slice provided.
func minCoins2(val int, coins []int) []int {
	slices.Sort(coins)
	res := make([]int, 0)
	i := len(coins) - 1
	for i >= 0 {
		if coins[i] < 1 {
			return []int{}
		}
		for val >= coins[i] {
			val -= coins[i]
			res = append(res, coins[i])
		}
		i -= 1
	}
	if val != 0 {
		return []int{}
	}
	return res
}
