function twoSum(nums: number[], target: number): number[] {
  for (let i = 0; i < nums.length; i++) {
    for (let n = 0; n < nums.length; n++) {
      if (nums[i] + nums[n] == target && n != i) {
        return [n, i];
      }
    }
  }
  return [0, 0];
}
