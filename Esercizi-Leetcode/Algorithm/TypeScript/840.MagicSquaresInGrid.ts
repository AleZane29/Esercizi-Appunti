/*Data una matrice contare quanti quadrati 3x3 ci sono che rispettano: 
-Elementi compresi tra 1 e 9
-Elementi non tutti uguali tra loro
-La somma di ciascuna colonna, riga e diagonale devono essere uguali 
*/
function numMagicSquaresInside(grid: number[][]): number {
	if (grid.length < 3 && grid[0].length < 3) {
		return 0;
	}
	let res = 0;
	for (let i = 0; i < grid.length - 2; i++) {
		for (let n = 0; n < grid[0].length - 2; n++) {
			let arr: number[] = [];
			let ver = true;
			for (let x = n; x < n + 3; x++) {
				arr.push(grid[i][x], grid[i + 1][x], grid[i + 2][x]);
			}
			arr.sort((a, b) => a - b);
			if (arr[0] == arr[8]) {
				ver = false;
			}
			if (ver) {
				arr.forEach((x) => {
					if (x <= 0 || x > 9) {
						ver = false;
						return;
					}
				});
			}
			let sum = grid[i][n] + grid[i][n + 1] + grid[i][n + 2];
			for (let x = i + 1; x < i + 3 && ver; x++) {
				if (grid[x][n] + grid[x][n + 1] + grid[x][n + 2] != sum) {
					ver = false;
				}
			}
			for (let x = n; x < n + 3 && ver; x++) {
				if (grid[i][x] + grid[i + 1][x] + grid[i + 2][x] != sum) {
					ver = false;
				}
			}
			if (
				!ver ||
				grid[i][n] + grid[i + 1][n + 1] + grid[i + 2][n + 2] != sum ||
				grid[i + 2][n] + grid[i + 1][n + 1] + grid[i][n + 2] != sum
			) {
				ver = false;
			}

			if (ver) {
				res++;
			}
		}
	}

	return res;
}
