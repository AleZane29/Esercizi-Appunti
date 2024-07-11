function reverseParentheses(s: string): string {
	let sArr = s.split('');
	let opened: number[] = [];
	for (let i = 0; i < sArr.length; i++) {
		if (sArr[i] == '(') {
			opened.push(i);
		} else if (sArr[i] == ')') {
			let toReverse = sArr
				.slice(opened[opened.length - 1] + 1, i)
				.reverse();
			sArr.splice(
				opened[opened.length - 1],
				i + 1 - opened.pop()!,
				...toReverse
			);
			i -= 2;
		}
	}
	return sArr.join('');
}
