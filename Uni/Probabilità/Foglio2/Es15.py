import math
from math import erf, sqrt

import matplotlib.pyplot as plt
import numpy as np


def normale_cdf(x, mu, sigma):
    # Approssimazione della distribuzione binomiale (Necessaria perché il calcolo della distribuzione normale raggiunge cifre enormi)
    return 0.5 * (1 + erf((x - mu) / (sigma * sqrt(2))))

def probabilita_vittoria(N, M):
    # Calcolo probabilità usando approssimazione della distribuzione binomiale.
    mu = N / 2
    sigma = sqrt(N) / 2
    soglia = (N - M) // 2 + 1
    return 1 - normale_cdf(soglia, mu, sigma)

# Esempio
N_total = 10**6
M_values = np.arange(0, 5001, 10)
probabilities = [probabilita_vittoria(N_total - M, M) for M in M_values]

# Grafico
plt.figure(figsize=(8, 6))
plt.plot(M_values, probabilities, label="Probabilità di vittoria di A", color='b')
plt.xlabel("Numero di voti fissi per A (M)")
plt.ylabel("Probabilità di vittoria di A")
plt.title("Probabilità di vittoria in funzione di M")
plt.grid(True)
plt.legend()

# Salvataggio grafico
pdf_path = "probabilita_vittoria.pdf"
plt.savefig(pdf_path, format="pdf")
plt.close()
