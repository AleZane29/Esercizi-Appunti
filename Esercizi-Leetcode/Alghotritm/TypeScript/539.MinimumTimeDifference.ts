//Dato array di orari restituire la differenza minima tra una coppia di essi
function findMinDifference(timePoints: string[]): number {
	let minutes: number[] = [];
	let res: number = Infinity;
	timePoints.forEach((x) => {
		minutes.push(
			Number.parseInt(x.split(':')[0]) * 60 + Number.parseInt(x.split(':')[1])
		);
	});
	for (let i = 0; i < minutes.length; i++) {
		for (let n = 0; n < minutes.length; n++) {
			if (n != i) {
				if (Math.abs(minutes[i] - minutes[n]) < res) {
					res = Math.abs(minutes[i] - minutes[n]);
				}
				if (1440 - Math.abs(minutes[i] - minutes[n]) < res) {
					res = 1440 - Math.abs(minutes[i] - minutes[n]);
				}
			}
		}
	}
	return res;
}
