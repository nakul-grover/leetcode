func maxProduct(nums []int) int {
    prefix := 1
    suffix := 1
    ans := math.MinInt
    n := len(nums)

    for i := 0; i < n; i++ {
        if prefix == 0 {
            prefix = 1
        }
        if suffix == 0 {
            suffix = 1
        }

        prefix *= nums[i]
        suffix *= nums[n-1-i]

        ans = max(ans, max(prefix, suffix))
    }

    return ans
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
