# Modification de tables

## Ajouter des données

```sql
INSERT INTO <nom table> [(nom de colonne)]
{
VALUES(<CONSTANTE>) | commande de recherche
}

# Exemple
INSERT INTO bon_buveur(nb_nom)
(
	SELECT distinct ...
):
#OR 
INSERT INTO vin VALUES(3.4,5.77);
```

## Mise à jour

```sql
UPDATE <nom table> SET ... WHERE ...;

Exemple
UPDATE vin SET degre=13 WHERE nom="gewurt"
```



## Suppression

```sql
DELETE FROM <nom table>
```



# Création de tables

```sql
CREATE TABLE <nom table> (
<def_colonne>
)

Exemple
CREATE TABLE buveur(
nb	number(3) primary key,
nom varchar2(20),
);
```