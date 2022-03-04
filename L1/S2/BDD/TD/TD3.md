# Exercice 1

```sql
4.
SELECT min(to_char(sysdate,'YYYY') - min(to_char(naissance('YYYY'))))
    as age_min FROM client;

5.
SELECT AVG(to_har(sysdate,'YYYY')-achat1) as anciennete_moy FROM client;


6.
SELECT AVG(to_char(sysdate,'YYYY')-to_char(naissance,'YYYH'))
    as anciennete_moy FROM client;

7.
SELECT SUM(qte) nb_prod FROM ligne;


8. 
SELECT idp,article FROM produit 
    WHERE prix = (Select max(prix) FROM produit);


9.
WITH T as (
    SELECT nom,prenom,to_char(sysdate,'YYYY')-to_char(naissance,'YYYY')
        AS age FROM client
    )
    SELECT T.nom, T.prenom, T.age FROM T 
        WHERE T.age = SELECT(min(T.age) from T);
```

# Exercice 2

```sql
1.
SELECT idCm,COUNT(idP) as nombre_article FROM ligne GROUP by idCm;

2.
SELECT idCm, SUM(qte) FROM ligne GROUP BY idCm;

3.
SELECT idCm,SUM(qte) FROM ligne
    GROUP BY idCm HAVING SUM(qte) => 3; 

4.
SELECT parrain, COUNT(*) as nb_filleuls FROM CLIENT GROUP BY parrain;

5.
SELECT y.nom, x.nom, COUNT(*) AS nb_filleuls FROM client x, client y 
    WHERE x.parrain = y.idCl 
        GROUP BY (x.parrain, y.nom);

6.
SELECT c1.idcl,c1.nom,count(c2.parrain) as nb_filleurs FROM client
    c1 left join client c2 on c1.idcl=c2.parrain
        group by c2.parain,c1.idcl,c1.nom order by c1.idcl;

7.
SELECT nom FROM rayon r, produit p
    WHERE r.idR=p.idR GROUP BY r.idR,nom HAVING COUNT(*) >= 3;

8.
SELECT nom FROM rayon WHERE idR=
    (SELECT idR FROM produit GROUP BY idR HAVING COUNT(*) =
        (SELECT MAX(COUNT(*)) FROM PRODUIT GROUP BY idR));

9. 
WITH T as 
    (SELECT nom,r.idR,COUNT(*) as nb_prod from produit p, rayon r
     GROUP BY r.idR,nom)
SELECT T.nom,T.idR,T.nbProd FROM T WHERE T.nbprod=(
        SELECT MAX(T.nbprod) FROM T);


10.
SELECT p.article FROM produit p,ligne l 
    WHERE p.idP=i.idP
        GROUP BY p.idP,p.article HAVING COUNT(p.idP) =
            (SELECT MAX(COUNT(idP)) FROM ligne GROUP BY idP);


11.
SELECT p.article, COUNT(l.idp) FROM produit p,ligne l WHERE l.idp=p.idp
    GROUP BY p.idp,p.article HAVING COUNT(l.idp)=
        (SELECT MAX(COUNT(idP)) FROM ligne GROUP BY idP);
```

    
