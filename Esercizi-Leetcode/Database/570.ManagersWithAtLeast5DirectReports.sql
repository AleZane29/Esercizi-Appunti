select name from Employee where id in (
Select E.managerId from Employee E
group by E.managerId
having count(E.managerId) > 4) 