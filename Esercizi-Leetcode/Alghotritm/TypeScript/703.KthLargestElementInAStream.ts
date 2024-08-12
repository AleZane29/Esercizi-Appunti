class KthLargest {
	private k: number;
	private nums: number[];

	constructor(k: number, nums: number[]) {
		this.k = k;
		this.nums = nums;
	}

	add(val: number): number {
		this.nums.push(val);
		this.nums.sort((a, b) => b - a);
		return this.nums[this.k - 1];
	}
}
