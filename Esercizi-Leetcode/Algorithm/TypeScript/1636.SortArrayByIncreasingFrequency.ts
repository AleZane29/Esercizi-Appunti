//Dato un array di numeri restituire l'array ordinato per frequenza di presenza di un numero e in caso di pari frequenza ordinare
//in modo decrescente
function frequencySort(nums: number[]): number[] {
	let numFreq: { num: number; freq: number }[] = [];
	for (let i = 0; i < nums.length; i++) {
		let ver = 1;
		for (let n = 0; n < numFreq.length; n++) {
			if (ver == 1 && numFreq[n] != null && numFreq[n].num == nums[i]) {
				ver = 0;
				numFreq[n].freq++;
			}
		}
		if (ver == 1) {
			numFreq.push({ num: nums[i], freq: 1 });
		}
	}

	let sortedData = numFreq.sort(
		(a, b) => (b.freq - a.freq) * 1000 + (a.num - b.num) / 10
	);
	let res: number[] = [];
	for (let n = sortedData.length - 1; n >= 0; n--) {
		for (let i = 0; i < sortedData[n].freq; i++) {
			res.push(sortedData[n].num);
		}
	}

	return res;
}
