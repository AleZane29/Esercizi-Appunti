function LIS(nums: number[]): number {
	let len: number[] = Array(nums.length).fill(1);
	let prev: number[] = Array(nums.length).fill(0);
	let LISlen: number = 1;
	let end: number = 0;
	prev[1] = 0;
	for (let i = 1; i < nums.length; i++) {
		for (let j = 0; j < i; j++) {
			if (nums[j] < nums[i]) {
				len[i] = len[i] < len[j] + 1 ? len[j] + 1 : len[i];
				prev[i] = j;
			}
		}
		if (len[i] > LISlen) {
			LISlen = len[i];
			end = i;
		}
	}
	//Stampa LIS
	printLIS(nums, end, prev);
	return LISlen;
}

function printLIS(nums: number[], i: number, prev: number[]): void {
	if (prev[i] != 0) {
		printLIS(nums, prev[i], prev);
	}
	console.log(nums[i]);
}
