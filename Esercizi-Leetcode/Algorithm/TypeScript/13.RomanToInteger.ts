/*
Trasforma un numero da romano a arabo
*/
function romanToInt(s: string): number {
	let ris = 0;
	for (let i = 0; i < s.length; i++) {
		switch (s.charAt(i)) {
			case 'I': {
				if (s.charAt(i + 1) == 'V') {
					ris += 4;
					i++;
				} else if (s.charAt(i + 1) == 'X') {
					ris += 9;
					i++;
				} else {
					ris += 1;
				}
				break;
			}
			case 'V': {
				ris += 5;
				break;
			}
			case 'X': {
				if (s.charAt(i + 1) == 'L') {
					ris += 40;
					i++;
				} else if (s.charAt(i + 1) == 'C') {
					ris += 90;
					i++;
				} else {
					ris += 10;
				}
				break;
			}
			case 'L': {
				ris += 50;
				break;
			}
			case 'C': {
				if (s.charAt(i + 1) == 'D') {
					ris += 400;
					i++;
				} else if (s.charAt(i + 1) == 'M') {
					ris += 900;
					i++;
				} else {
					ris += 100;
				}
				break;
			}

			case 'D': {
				ris += 500;
				break;
			}

			case 'M': {
				ris += 1000;
				break;
			}
		}
	}
	return ris;
}

// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.
