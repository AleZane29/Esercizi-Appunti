function minDifference(nums: number[]): number {
	if (nums.length <= 4) {
		return 0;
	}
	let off = nums.length - 4;
	nums.sort((a, b) => a - b);
	let minDiff = nums[off] - nums[0];
	for (let i = 1; i < 4; i++) {
		if (nums[i + off] - nums[i] < minDiff) {
			minDiff = nums[i + off] - nums[i];
		}
	}
	return minDiff;
}
