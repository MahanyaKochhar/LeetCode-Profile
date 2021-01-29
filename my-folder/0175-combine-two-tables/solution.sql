select Person.FirstName,Person.LastName,Address.city,Address.state
from Person
left join Address on Person.PersonId=Address.PersonId

