#Data una parola converte ogni lettera con la rispettiva posizione nell'alfabeto e somma tutte le singole cifre per k volte
import string


class Solution(object):
    def getLucky(self, s, k):
        app=0
        res=0
        for i in s:
            for i in str(string.ascii_lowercase.index(i)+1):
                res+=int(i)
            app = res
        for n in range(k-1):
            res = 0
            for i in str(app):
                res +=int(i)
            app = res
        return res

