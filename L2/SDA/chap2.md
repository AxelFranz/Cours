# Spécifications des files.

Une file est un conteneur d'objets que l'on manipule avec 3 opérations fondamentales

* Ajouter un objet en queue de file (adjq)

* Supprimer un objet en tête de file (supt)

* accéder à l'objet en tête de file (tete)



FILE0(TRIV) étend BASE

Sorte: File

Opérations : 

Filenouv -> File

adjq : File S -> File

supt : File -> File

tete : File -> S

vide : File -> Bool

lgr : File -> Nat

Préconditions : f : File; x : S

* pre : supt(f) et tete (f) : non vide (f)



Axiomes : f: File ; x : S

vide(filenouv) = Vrai

lgr(filenouv) = 0

vide(adjq(f,x))=faux

lgr(adjq(f,x))=1+lgr(f)

tete(adjq(f,x)) = si vide (f) alors x

                            sinon tete(f) 

suppt(addjq(f,x))=si vide(f) alors filenouv

                                sinon adjq(supt(f),x)
