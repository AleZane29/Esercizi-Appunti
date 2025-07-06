//Data una parola da digitare, trovare il minor numero di volte che i tasti vengano premuti modificando il layout della tastiera di un
//vecchio cellulare (Premere più volte lo stesso tasto per selezionare lettera diversa)
function minimumPushes(word: string): number {
	let wordFreq: { words: string; freq: number }[] = [];
	for (let i = 0; i < word.length; i++) {
		let ver = 1;
		for (let n = 0; n < wordFreq.length; n++) {
			if (
				ver == 1 &&
				wordFreq[n] != null &&
				wordFreq[n].words == word[i]
			) {
				ver = 0;
				wordFreq[n].freq++;
			}
		}
		if (ver == 1) {
			wordFreq.push({ words: word[i], freq: 1 });
		}
	}

	let sortedData = wordFreq.sort((a, b) => b.freq - a.freq);
	let res = 0;
	for (let i = 0; i < sortedData.length; i++) {
		res += sortedData[i].freq * (Math.floor(i / 8) + 1);
	}
	return res;
}
