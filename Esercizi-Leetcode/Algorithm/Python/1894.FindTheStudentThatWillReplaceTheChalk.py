#Dato un gesso e n studenti pari a n problemi che richiedono chalk[i] gesso, restituire lo studente che dovrà cambiare il gesso sapendo
#che lo studente i risolverà sempre il problema i
class Solution(object):
    def chalkReplacer(self, chalk, k):
        if len(chalk)==1: 
            return 0
        summ=sum(chalk, 0)
        while k>summ:
            k-=summ
        i=0
        while k>0:
            k-=chalk[i]
            if k<0:
                return i
            if i==len(chalk)-1:
                i=0
            else : 
                i+=1
        return i

        