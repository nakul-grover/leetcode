func rotate(matrix [][]int)  {

    var n int = len(matrix)
    for i:=0;i<n;i++ {
        for j:=0;j<=i;j++ {
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j];
        }
    }
    for i:=0;i<n;i++ {
        reverse(matrix[i]);
    }

    return;

}
func reverse(arr []int) {
    l, r := 0, len(arr)-1
    for l < r {
        arr[l], arr[r] = arr[r], arr[l]
        l++
        r--
    }
}