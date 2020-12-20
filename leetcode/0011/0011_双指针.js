var maxArea = function(height) {
    let i = 0, j=height.length-1
    let max_area = 0
    while (j-i>0) {
        if(height[i] < height[j]) {
            area = height[i]*(j-i)
            i++
        }
        else if(height[i] > height[j]) {
            area = height[j]*(j-i)
            j--
        }
        else if(height[i] == height[j]) {
            area = height[j]*(j-i)
            i++
            j--
        }
        if(area > max_area) max_area = area
    }
    return max_area
}

console.log(maxArea([1,8,6,2,5,4,8,3,7]))
//双指针 执行用时：92 ms 内存消耗：38.4 MB  复杂度低 O(n)