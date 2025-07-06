import random
from collections import defaultdict

import matplotlib.pyplot as plt

N_SIM = 500000
VITTORIE = [0]*12
DURATE = defaultdict(int)

for _ in range(N_SIM):
    posizioni = [0]*12
    mosse = 0
    while max(posizioni) < 19:
        dado1, dado2 = random.randint(1, 6), random.randint(1, 6)
        somma = dado1 + dado2
        col = somma - 1
        posizioni[col] += 1
        mosse += 1
    vincitore = posizioni.index(19)
    VITTORIE[vincitore] += 1
    DURATE[mosse] += 1

# Grafico 1: probabilità di vittoria per colonna
plt.figure(figsize=(8,4))
k = list(range(1, 13))
p_vittoria = [v/N_SIM for v in VITTORIE]
plt.bar(k, p_vittoria)
plt.xlabel("Colonna k")
plt.ylabel("Probabilità di vittoria")
plt.title("Probabilità di vittoria per colonna")
plt.savefig("vittorie_colonne.pdf", format="pdf")
plt.close()

# Grafico 2: probabilità della durata
plt.figure(figsize=(10,4))
N = sorted(DURATE.keys())
p_durata = [DURATE[n]/N_SIM for n in N]
plt.plot(N, p_durata)
plt.xlabel("Durata in mosse")
plt.ylabel("Probabilità")
plt.title("Distribuzione della durata del gioco")
plt.savefig("durata_gioco.pdf", format="pdf")
plt.close()
