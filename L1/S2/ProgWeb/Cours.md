# Cours

## Introduction

On va utiliser le trio HTML/CSS/JS

## Chapitre 1 : HTML et structuration

### Qu'est-ce que le HTML ?

Langage à base de balises hiérarchiques

Le HTML n'influe pas sur l'apparence du texte (le CSS est là pour ça)

Un code doit être propre et clair pour être compréhensible par le plus grand nombre

Une balise est sous la forme

```html
<tag>Texte</tag>
<tag attribut="non">test</tag>
```

Un patron de base ressemble à 

```html
<!DOCTYPE html>                 <!-- Sers à préciser la version d'HTML-->
<html>                             <!-- Agit comme la racine de la page, tout doit être dedans -->
    <head>                        <!--Toutes les balises dedans seront des métadonnées -->
       <meta charset="utf-8">   <!-- Utilisation de l'utf-8 -->
       <title>Salut</title>     <!-- Sers à définir le titre de l'onglet -->
    </head>                     <!-- Fin du head -->
    <body>                      <!-- Tout ce qui est dedans sera affiché jusqu'à la fin de la balise -->
        <h1>Coucou</h1>         <!-- Pour les titres : Va jusqu'à h6 -->
        <p>Hello</p>
    </body>
</html>
```

Si jamais, on veut vérifier notre structure, on peut utiliser [ce site](https://validator.w3.org/#validate_by_upload).

Quelques exemples de balises

```html
<!-- Pour insérer une image -->
<img src="chemin" alt=" exte de remplacemnt en cas d'erreur ou pour de l'audiodescription"> 

<!-- Pour de l'hypertexte -->
<a href="page.html" title="Titre d'infobulle"> Clique ici </a>
<a href="url"> Clique ici </a>

<!-- Les listes -->
<ol> <!-- Listes numérotées -->
    <li> Element 1</li>
    <li> Element 2</li>
</ol>
<ul> <!-- Liste non numérotée -->
    <li> Element 1</li>
    <li> Element 2</li>
</ul>

<!-- Pour des définitions -->
<dl> 
    <dt>Terme à définir</dt>
    <dd>Définition</dd>
</dl>

<!-- Tableaux,à ne quasi jamais utiliser  -->
<table>
    <tr>
        <th>Colonne 1</th>
        <th>Colonne 2</th>
        <td>Donnée ligne 1</td>
        <td>Donnée ligne 2</td>
    </tr>
</table>

<!-- Les editions de texte-->
<strong>En gras</strong>
<em>Italique</em>
<mark>Surligné</mark>
<del>Barré</del>
```

### Différence entre div et span (blocs génériques = pas de sens sémiotique)

Les \<div> ont des retours à la ligne entre eux et les span non.

### Différence entre id et class

L'id est unique

La classe est multiple 

## Chapitre 2 : Utilisation du CSS et approfondissement de l'HTML

### Insérer une page de style dans un fichier HTML

```html
<!-- Pour tout le document -->
<link rel="stylesheet" href="src.css">

<!-- Pour juste une partie -->
<style> </style>
```

### Pour définir une classe ou un id

```css
.classe
{
    /* Ici je définis une classe */
}

#id
{
    /* Ici je définis un id */    
}
```

## Chapitre 3 : Mise en place d'un site dynamique

## Chapitre 4 : Introduction au JS

Pour inclure du js dans une page on utilise

```html
<script src="fichier.js"></script>
```

En général c'est à la fin du fichier que l'on inclus le fichier JS au cas où le JS ne charge pas, on aura au moins le JS.

**Le JS est un langage orienté objet**



## Chapitre 5 : Interaction HTML / JS



## Chapitre 6 : Approfondissment JS
