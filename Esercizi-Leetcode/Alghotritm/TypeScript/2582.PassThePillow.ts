//Dato n numero di persone e time numero di passaggi del testimone ritornare a chi è in mano, sapendo che una volta giunto a termine
//viene ripassato all'indietro
function passThePillow(n: number, time: number): number {
	if (Math.floor(time / (n - 1)) % 2 == 0) {
		return (time % (n - 1)) + 1;
	}
	return n - (time % (n - 1));
}
