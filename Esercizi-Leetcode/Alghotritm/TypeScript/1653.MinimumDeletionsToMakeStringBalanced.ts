//Data una stringa formata da a e b trovare il n° minimo di eliminazioni da fare perché la stringa sia ordinata alfabeticamente
function minimumDeletions(s: string): number {
	//Rimuove a iniziali e b finali
	let i = 0;
	for (i; i < s.length; i++) {
		if (s[i] != 'a') {
			break;
		}
	}
	let n = s.length - 1;
	for (n; n >= 0; n--) {
		if (s[n] != 'b') {
			break;
		}
	}
	s = s.substring(i, n + 1);

	let aDx: number = 0;
	let bSx: number = 0;

	for (let i = 0; i < s.length; i++) {
		if (s[i] == 'a') {
			aDx++;
		}
	}
	let min: number = aDx;
	for (let i = 0; i < s.length; i++) {
		if (s[i] == 'a') {
			aDx--;
		} else {
			bSx++;
		}
		if (aDx + bSx < min) {
			min = aDx + bSx;
		}
	}
	return min;
}
