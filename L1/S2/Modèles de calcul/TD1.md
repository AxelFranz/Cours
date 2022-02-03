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



## Exercice 2

*  C'est la fonction x -> 2x
* C'est la fonction f-> f(x)
* C'est la fonction x -> x(3
* C'est la fonction (x,y) -> x + y

* C'est la fonction (x,x2) -> 2 * x2
* C'est la fonction x -> z -> z + x
* C'est la fonction (x,y) -> z -> x(3) + z
* C'est la fonction x -> x(x(1))
* C'est la fonction (((f,a) -> f(a))(x))(a), ce qui équivaut à a(x) 



## Exercice 3

* On remplace juste le dernier x par g
* Le y est lié donc on ne remplace rien

* On remplace le premier f par g
* On remplace le x
* On remplace juste le premier x et le dernier

* On remplace le x juste avant

* On modifie les 2 premieres occurences de x

## Exercice 4
* Ca se réduit en 6
* Ca s'écrit (+ 5)
* Ca se réduit en 3