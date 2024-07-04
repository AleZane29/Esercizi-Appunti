/*
Dato un array di stringhe restituisce il prefisso comune a tutte
*/
function longestCommonPrefix(strs: string[]): string {
	let ver: boolean = true;
	let i: number = -1;
	if (strs.length > 1) {
		while (i < strs[0].length && ver == true) {
			i++;
			for (let n = 0; n < strs.length; n++) {
				if (strs[0][i] != strs[n][i]) {
					ver = false;
				}
			}
		}
		return strs[0].slice(0, i);
	} else {
		return strs[0];
	}
}
