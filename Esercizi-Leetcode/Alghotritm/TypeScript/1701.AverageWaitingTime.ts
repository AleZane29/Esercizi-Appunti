//Data una matrice contenente il tempo di arrivo e tempo per servirlo calcolare il tempo medio impiegato per servire tutti i clienti
function averageWaitingTime(customers: number[][]): number {
    let time: number = 0;
    let sumTimes: number = 0;
    for (let i = 0; i < customers.length; i++) {
        if (customers[i][0] > time) {
            time = customers[i][0];
        }
        sumTimes += time + customers[i][1] - customers[i][0];
        time = time + customers[i][1];
    }
    return sumTimes / customers.length;
}
