function kthCharacter(k: number): string {
	let word: string = 'a';
	while (word.length < k) {
		let nextWord: string = '';
		for (let i = 0; i < word.length; i++) {
			nextWord += String.fromCharCode(
				word.charCodeAt(i) === 122 ? 97 : word.charCodeAt(i) + 1
			);
		}
		word += nextWord;
	}
	return word[k];
}
