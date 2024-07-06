/*
Restituisce true se esistono tre numeri dispari consecutivi nell'array, altrimenti false
*/
function threeConsecutiveOdds(arr: number[]): boolean {
	let consOdd = 0;
	for (let i = 0; i < arr.length; i++) {
		if (arr[i] % 2 == 1) {
			consOdd++;

			if (consOdd >= 3) {
				return true;
			}
		} else {
			consOdd = 0;
		}
	}
	return false;
}
