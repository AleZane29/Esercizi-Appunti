-- Da due tabelle "Person" e "Indirizzo" restituisce un'unica tabella con null come valore se l'indirizzo non è presente
select P.firstName, P.lastName, A.city, A.state
from Person AS P left join Address AS A ON P.personId=A.personId