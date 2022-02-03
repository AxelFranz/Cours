Ici K = C ou R

## Un espace vectoriel, qu'est-ce que c'est ?

C'est un ensemble de vecteurs dont le but est de généraliser la notion de vecteurs.
$$
\text{Soit P un plan, la translation envoyant A sur B est représentée par le vecteur }\overrightarrow(AB)
\\
\text{Deux vecteurs sont égaux dès qu'ils représentent la même translation}
$$
On note V(P) l'ensemble des vecteurs du plan

L'addition et la multiplication sont valables et le vecteur nul existe.
$$
\text{Un K espace vectoriel est un ensemble } V\text{ munit d'un élément }0_v\in V\\\text{ d'une somme }+_v:V*V\rightarrow V \text{ et d'un produit externe}*_v:K*V\rightarrow V\text{ tel que :}
\\1.\space u+_vv=v+_vu
\\2. \space (u+_vv)+_vw = u+_v(v+_vw)
\\3. \space u+_v0_v = u
\\4. \space \forall u\in V(P),\exist v  \in V(P) / u+_vv=0_v
\\5. \space 1*_vu=u
\\6. \space (\lambda_v*_v\phi)*_vu= \lambda*_v(\phi*_vu)
\\7. \space \lambda*_v(u+_vv)=\lambda u+\lambda v
\\8. \space \text{Distributivité}
$$
Propriété et preuves dans le bouquin Exo7

* K est un K espace vectoriel => R est un R-espace vectoriel, C est un C-espace vectoriel



**Pour prouver un espace vectoriel, il suffit de montrer les 8 axiomes**



### Est-ce que V*W a naturellement une structure de K-espace vectoriel si V et W sont des K-espaces vectoriels



# Sous-espaces vectoriels

C'est un espace vectoriel inclus dans un autre espace vectoriel tel que les 0,+,* sont les mêmes
$$
\text{Soit }(V,+,*) \text{ un K-espace vectoriel.}\\ \text{Un sous-espace vectoriel de  }(V,+,*) \text{ est une partie }E\subseteq V/ \forall x,y\in E \text{ alors }x+y\in E \text{ et } \forall \lambda\in\R \text{ alors }\lambda*x\in E
\\\text{On peut alors restreindre et corestreindre + et x}
\\\text{On a } +:V*V\rightarrow V \text{ donc } x^{E}_{|E*E}\rightarrow E
\\\text{ et }*:K*V\rightarrow V \text{ donc } x^{E}_{|K*E}\rightarrow E
$$
Propriété :

E inclus dans V est un soudans E

s-espace vectoriel dès lors que 

- Pour tout x et y appartenant à e, alors x+y sont dans E

- Pour tout lambda dans K et x dans E alors Lambda*x est 

- E est non vide
  $$
  \text{Soit}\space (V,+,*) \text{ un K-espace vectoriel}\\
  \text{et }(E,+,*)\text{ un sous-espace vectoriel, alors }(E,+,*)\text{ est un K-espace vectoriel}
  $$
  

EXO 8,11,13 SUR FEUILLE A RENDRE POUR MERCREDI