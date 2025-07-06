//Dato un array di stringhe contenente i log dei movimenti nelle cartelle restituire il numero di operazioni minimi da effettuare per
// tornare nella cartella di partenza
function minOperations(logs: string[]): number {
	let deep: number = 0;
	for (let i = 0; i < logs.length; i++) {
		if (logs[i] == '../') {
			if (deep > 0) {
				deep--;
			}
		} else if (logs[i] != './') {
			deep++;
		}
		console.log(deep);
	}
	return deep;
}
