/*
Restituisce gli indici dei valori di un array che sommati tra loro danno il valore target
*/
//Costo: O(n^2)
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

//Costo: O(n log(n))
function twoSum2(nums: number[], target: number): number[] {
	let app: number[] = [];
	nums.forEach((x) => app.push(x));
	nums.sort((a, b) => a - b);
	let i = 0;
	let j = nums.length - 1;
	while (i < j) {
		if (nums[i] + nums[j] < target) {
			i++;
		} else if (nums[i] + nums[j] > target) {
			j--;
		} else {
			return [app.indexOf(nums[i]), app.lastIndexOf(nums[j])];
		}
	}
	return [0, 0];
}
