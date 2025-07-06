//Dati due array con nomi e altezze restituisce i nomi ordinati in base all'altezza
function sortPeople(names: string[], heights: number[]): string[] {
	let data: { name: string; val: number }[] = [];
	for (let i = 0; i < names.length; i++) {
		data.push({ name: names[i], val: heights[i] });
	}
	let sortedData = data.sort((a, b) => b.val - a.val);
	console.log(sortedData);
	let res: string[] = data.map((entry) => entry.name);
	return res;
}
