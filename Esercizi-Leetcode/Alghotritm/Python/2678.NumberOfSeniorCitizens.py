#Data una lista di stringhe contenenti n° tel, genere, età e posto, restituisce il numero di persone over 60
class Solution(object):
    def countSeniors(self, details):
        count =0
        for i in details:
            if i[11]>"6" or (i[11]=="6" and i[12]>"0"):
                count+=1
        return count