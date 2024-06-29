function isValid(s: string): boolean {
	let opened: string = '';
	for (let i = 0; i < s.length; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			opened += s[i];
		} else {
			if (s[i] == ')' && opened[opened.length - 1] != '(') {
				return false;
			}
			if (s[i] == ']' && opened[opened.length - 1] != '[') {
				return false;
			}
			if (s[i] == '}' && opened[opened.length - 1] != '{') {
				return false;
			}
			opened = opened.slice(0, opened.length - 1);
		}
	}
	if (opened.length != 0) {
		return false;
	}
	return true;
}
