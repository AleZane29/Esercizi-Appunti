//Data X stringa, trovare Z stringa più breve palindroma che contenga la sotto sequenza X. CP=Stringa palindroma che contiene la sotto sequenza X
//Idea: Dividere il problema in sotto problemi:
//  Caso 1: Se X[0]==X[n-1] -> Z[0]=X[0] e Z[m-1]=X[0]
//  Caso 2: Se X[0]!=X[n-1] -> min{Sotto_caso1, Sotto_caso2}
//    Sotto_caso1 -> Z[0]=X[0] e Z+=CP(X[1...n-1])
//    Sotto_caso2 -> Z[m-1]=X[n-1] e Z+=CP(X[0...n-2])

function SCP(X: string): string {
	let Z: string = '';
	let j: number = X.length - 1;
	for (let i = 0; i < j; i++) {
		if (X[i] == X[j]) {
			Z = Z.slice(0, Z.length / 2) + X[i] + X[i] + Z.slice(Z.length / 2);
			j--;
		} else {
			let case1 = SCP(X.slice(i + 1, j));
			let case2 = SCP(X.slice(i, j - 1));
			if (case1.length < case2.length) {
				Z =
					Z.slice(0, Z.length / 2) +
					X[i] +
					case1 +
					X[i] +
					Z.slice(Z.length / 2);
			} else {
				Z =
					Z.slice(0, Z.length / 2) +
					X[j] +
					case2 +
					X[j] +
					Z.slice(Z.length / 2);
			}
		}
	}
	return Z;
}

// function SCP(X: string): string {
// 	let Z: string = '';
// 	let j: number = X.length - 1;
// 	for (let i = 0; i < j; i++) {
//         console.log("X[i]", X[i], "X[j]", X[j]);
// 		if (X[i] == X[j]) {
// 			Z = Z.slice(0, Z.length / 2) + X[i] + X[i] + Z.slice(Z.length / 2);
// 			j--;
// 		} else {
// 			let case1 = SCP(X.slice(i + 1, j));
// 			let case2 = SCP(X.slice(i, j - 1));
// 			if (case1.length < case2.length) {
//                 console.log("case:", case1);
// 				Z =
// 					Z.slice(0, Z.length / 2) +
// 					X[i] +
// 					case1 +
// 					X[i] +
// 					Z.slice(Z.length / 2);
// 			} else {
//                 j--;
//                 i--;
//                 console.log("case:", case2);
// 				Z =
// 					Z.slice(0, Z.length / 2) +
// 					X[j] +
// 					case2 +
// 					X[j] +
// 					Z.slice(Z.length / 2);
// 			}
// 		}
//         console.log("Z:", Z, "X:", X);
// 	}
// 	return Z;
// }

// console.log(SCP("abbcda"));
