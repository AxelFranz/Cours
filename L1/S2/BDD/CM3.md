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

## Supprimer une table

```sql
DROP TABLE <nom table>;
```

# Création de vue

```sql
CREATE VIEW <NOM>
AS spécification;
```

## Contrainte d'intégrité

* Contrainte de domaine

  * Valeurs possibles pour une colonne

  * Valeur nulle impossible

* Contrainte d'unicité et de clé primaire

* Contrainte référentielle





# Langage de contrôle des données

* GRANT : Attribution de droit d'accès

* REVOKE : Suppression de droits d'accès

* COMMIT : Prise en compte des dernières transactions pour une mise à jour des données

* ROLLBACK : Dans le nom

```sql
GRANT <privilege_type> ON <TABLE> TO utilisateur  
```

  

# Extensions SQL2

```sql
# Nouveau types de données : DATE, TIME, TIMESTAMP
SELECT sysdate from dual(système);
to_char(date,<format>); # Pour les formats, se referrer à Internet

# Traitement des chaînes de caractère
UPPER(<str>);
LOWER(<str>);
SUBSTR(<str>,<position>,<nb_char>);

# Renommer des colonnes
... AS ...;

```

# Jointure externes (OUTER JOIN )