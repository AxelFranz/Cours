# TD1: Spécification concrète d'un stock et programmation fonctionnelle

| Ref | qte |
| --- | --- |
| 5   | 4   |
| 6   | 3   |
| 7   | 2   |

Spec RED étend NAT sorte Ref fspec
Spec STOCK étend BASE
Sorte Stock
opérations:

- créer_stock: $\empty\ \rightarrow$ Stock
- new_ref: Stock Ref Nat -> Stock
- add_qte: Stock Ref Nat -> Stock
- Sup_ref: Stock Ref -> Stock
- cord_stock: Stock -> Nat
- vider_stock: Stock -> Stock
- est_vide: Stock -> Bool
- quantite: Stock Ref -> Nat
- Ref_epuise: Stock Ref -> Bool
- Sup_qte: Stock Ref Nat -> Stock
- Ref_exist: Stock Ref -> Bool
- Stock_vide: Stock -> Stock
- Stock_total
- est_rempli: Stock -> Bool

## Préconditions:

S:Stock, R:Ref, q:Nat

- new_ref S R q: non(Ref_exit S R) ou non(est_rempli S)
- sup_ref S R: Ref_exist S R
- add_qte S R q: Ref_exist S R
- sup_qte S R q: Ref_exist S R ou (quantité S R) $\ge$ q
- quantité S R: Ref_exist S R
- Ref_epuise S R: Ref_exist S R

## Axiomes

S : Stock, R1 R2 : Ref, q1 q2 Nat

add_qtc(new_ref s r1 q1) r2 q2 =

       si r1==r2 : new_ref s r1 (q1+q2)

       sinon new_ref(s r1 q1) r2 q2 =

sup_ref(new ref s r1 q1) r2=

    si r1==r2 : s

    sinon newref(sup_ref s r2) r1 q1

card_stock(new_ref s r1 q1) = (card stock s) +1

Sachant que card_stock creer_stock = 0

est_vide(new_ref s r1 q1) = False

est_vide creer_stock = True

vider_stock s = creer_stock

quantite(new_ref s r1 q1) r2= 

    si r1==r2 : q1 

    sinon quantité s r2

ref_exist(new_ref s r1 q1) r2 = 

    si r1==r2 : True

    sinon ref_exist s r2

stock_vide creer_stock = True

stock_vide(new_ref s r1 q1)=

    si q1==0

        new_ref(stock_vide s) r1 q1

    sinon 

        stock_vide s

stock_total creer_stock=0

stock_total(new_ref s r1 q1)=

    q1+stock_total s

est_rempli s = card_stock s
