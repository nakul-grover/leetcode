import "sort"

func nextPermutation(nums []int) {
    i := len(nums) - 2
    pivot := -1

    for i >= 0 {
        if nums[i] < nums[i+1] {
            pivot = i
            break
        }
        i--
    }

    if pivot == -1 {
        sort.Ints(nums)
        return
    }

    j := len(nums) - 1
    for nums[j] <= nums[pivot] {
        j--
    }

    nums[pivot], nums[j] = nums[j], nums[pivot]

    sort.Ints(nums[pivot+1:])
}
