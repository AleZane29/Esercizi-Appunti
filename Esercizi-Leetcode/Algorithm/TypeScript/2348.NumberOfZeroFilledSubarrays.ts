function zeroFilledSubarray(nums: number[]): number {
	let res: number = 0;
	for (let i = 0; i < nums.length; i++) {
		let count: number = 0;
		while (i < nums.length && nums[i] == 0) {
			count++;
			res += count;
			i++;
		}
	}
	return res;
}
