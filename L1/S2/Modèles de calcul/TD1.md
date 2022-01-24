# TD-1

## Exercice 1

* C'est une abstraction : C'est x(3) et son sous-terme est une application. 
  * On l'écrit aussi  λx.x 3
  * C'est déjà parenthésé au maximum
  
* C'est une abstraction, son corps est composé d'une abstraction comprenant une application et une constante
  * On ne peut pas supprimer les parenthèses
  
  * On peut écrire (λx.(λy.(x 3)))
  
* C'est une abstraction avec des applications
  
  * On peut toutes les enlever
  
  * On peut écrire (λa.(a(λb.(b a))))

* C'est une application d'abstractions
  * Les parenthèses ne sont pas facultatives
* Rip le E, j'étais aux toilettes
* Pour le f
  * On peut virer les parenthèses
  * On rajoute des parenthèses autour, dans la deuxième abstraction, et autour de ladite abstraction

* Pour le g
  * On ne peut rien virer
  * On peut rajouter beaucoup de parenthèses
* Pour le h
  * On peu
  * On peut rajouter beaucoup de parenthèses