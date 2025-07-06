//Dati rowSum e colSum array delle somme relative a i valori di colonne e righe, trovare una matrice che rispetti le somme
function restoreMatrix(rowSum: number[], colSum: number[]): number[][] {
	let res: number[][] = [];
	for (let row = 0; row < rowSum.length; row++) {
		let newRow: number[] = Array(colSum.length).fill(-1);
		res.push(newRow);
	}

	//Pezzo non necessario che assegna prima alla diagonale il valore minimo tra rowSum e colSum relativi alla cella
	/*let min = rowSum.length < colSum.length ? rowSum.length : colSum.length;
	for (let i = 0; i < min; i++) {
		if (rowSum[i] > colSum[i]) {
			for (let n = 0; n < rowSum.length; n++) {
				res[n][i] = 0;
			}
			res[i][i] = colSum[i];
		} else {
			for (let n = 0; n < colSum.length; n++) {
				res[i][n] = 0;
			}
			res[i][i] = rowSum[i];
		}
	}*/
	for (let i = 0; i < rowSum.length; i++) {
		for (let j = 0; j < colSum.length; j++) {
			const minVal = Math.min(rowSum[i], colSum[j]);
			res[i][j] = minVal;
			rowSum[i] -= minVal;
			colSum[j] -= minVal;
		}
	}
	return res;
}
