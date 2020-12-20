var maxArea = function(height) {
    let max_area = 0
    for (let i = 0; i < height.length; i++) {
        let j=i, area,h
        while (j < height.length) {
            h = height[j]>height[i]?height[i]:height[j]
            area=h*(j-i)
            if (area > max_area) max_area = area
            j++
        }
    }
    return max_area
}
console.log(maxArea([2,3,4,5,18,17,6]))
//单指针 执行用时：856 ms 内存消耗：38.9 MB  复杂度高 O(n^2)
