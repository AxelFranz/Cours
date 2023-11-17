/* QUESTION 1 */
SET SERVEROUTPUT ON;
DECLARE
    v_depart  VARCHAR;
    v_arrivee VARCHAR;
    nb_etapes VARCHAR;
BEGIN
    SELECT villeDepart INTO v_depart, villeArrivee INTO v_arrivee
    FROM Circuit
    WHERE identifiant=9;
    SELECT COUNT(distinct ordre) INTO nb_etapes
    FROM Etape
    WHERE identifiant=9;
    DBMSOUTPUT.PUT_LINE('Informations sur le circuit 9:'||v_depart||', '||v_arrivee||', '||nb_etapes||' étapes');
END;

/* QUESTION 2 */
SET SERVEROUTPUT ON;
DECLARE
    numVisite INTEGER;
    message VARCHAR;
    ACCEPT aNomVille VARCHAR DEF 'Ribeauvillé'  PROMPT 'Ville : ';
    ACCEPT aNomLieu  VARCHAR DEF 'Ribeaupierre' PROMPT 'Lieu : ' ;
    ACCEPT aPays     VARCHAR DEF 'France'       PROMPT 'Pays: '  ;
BEGIN
    SELECT COUNT(*) INTO numVisite
    FROM Etape
    WHERE nomLieu=&aNomLieu
        AND ville=&aNomVille
        AND pays =&aPays
    ;

    IF &numVisite=0
    THEN
        DELETE FROM LieuAVisiter
        WHERE nomLieu=&aNomLieu
              AND ville=&aNomVille
              AND pays =&aPays
        ;
        message:='ok';
    ELSE
        message:='Impossible';
    ENDIF;
    DMBSOUTPUT.PUT_LINE(message);
END;

/* QUESTION 3 */
set serveroutput on;
CREATE OR REPLACE PROCEDURE BloqueResa(nbDay INTEGER) IS
DECLARE 
    message VARCHAR;
    n INTEGER
BEGIN
    UPDATE Circuit
    SET nbPlaceDisponible=0
    WHERE dateDepart - sysdate < &nbDay;
    IF SQL%NOTFOUND THEN
        message:='Aucune ligne modifiée';
    ELSE
        n:=SQL%ROWCOUNT
        message:=To_char(n) || ' circuits modifés';
    ENDIF;
    DBMSOUTPUT.PUT_LINE(&message);
END;

/* Question 5*/

CREATE OR REPLACE FUNCTION Prix(numCircuit INTEGER) RETURN INTEGER
IS
DECLARE
    iPrixIns INTEGER;
    iPrixEt INTEGER;
BEGIN

    SELECT prixInscription INTO iPrixIns
    FROM Circuit
    WHERE identifiant=&numCircuit
    ;

    SELECT SUM(L.prix) INTO iPrixEt
    FROM LieuAVisiter L, Etape E
    WHERE E.identifiant=numCircuit 
            AND E.nomLieu=L.nomLieu 
        AND E.ville=L.ville
        AND E.pays=L.pays
    ;
    iPrixIns:=iPrixIns+iPrixEt;
    RETURN iPrixIns;
END;

/* QUESTION 9 */

SELECT
FROM
WHEER
ORBER BY ASC
DELETE FROM Etape
WHERE
;
UPDATE
SET
WHERE
;
