select P.firstName, P.lastName, A.city, A.state
from Person AS P left join Address AS A ON P.personId=A.personId