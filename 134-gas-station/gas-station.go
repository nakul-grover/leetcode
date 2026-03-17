func canCompleteCircuit(gas []int, cost []int) int {
    totalCost := 0
    totalGas := 0
    n := len(gas)

    for i:=0;i<n;i++ {
        totalCost +=cost[i]
        totalGas += gas[i]
    }
    if totalCost > totalGas {
        return -1
    }
    ans := 0
    currFuel := 0
    for i:=0 ;i<n;i++ {
        currFuel += gas[i] - cost[i]
        if currFuel < 0 {
            ans = i+1
            currFuel = 0
        }
    }
    return ans;


}