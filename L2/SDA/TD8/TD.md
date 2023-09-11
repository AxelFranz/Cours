# TD8 - Suite

## g.1

Rappel structure 
```
typedef struct s_noeud{
    node_type type;
    struct s_noeud* f1;
    S v1;
    struct s_noeud* f2;
    S v2;
    struct s_noeud* f3;
    S v3;
    struct s_noeud* f4;
    S v4;
}
```

est_feuille: -| est_vide(a)
{
    return est_vide(a->f1);
}

```c
void insertion_feuille(x,a) -| est_feuille(a)
{
    if(a->type == type2fils){
        a->type == type2fils;
        a->f3 == NULL;
        if(a->v1 < x) a->v2 = x;
        else {
            a->v2 = a->v1;
            a->v1 = x;
        }
    } else if (a->type == type3fils){
        a->f4 = NULL;
        if(a->v2 < x) a->v3 = x;
        else if (a->v1 < x){
            a->v3 = a->v2;
            a->v2 = x;
        } else {
            a->v3 = a->v2; a->v2 = a->v1; a->v1 = x;
        }
    } else {
        erreur();
    }
}


Arb234 rem1g(Arb234 a){
    a->type = type3fils;
    a->f3 = a->f2;
    a->v2 = a->v1;
    a->f2 = enrac2(a->f1->f3, a->f1->v3, a->f1->f4);
    Arb234 tmp = a->f1;
    a->v1 = a->f1->v2;
    a->f1 = enrac2(a->f1->f1, a->f1->v1, a->f1->f2);
    free(tmp);
    return a;
}

// autre version
Arb234 rem1g(Arb234 a){
    a->type = type3fils;
    Arb234 f1 = a->f1;
    a->f3 = a->f2;
    a->v2 = a->v1;
    a->v1 = f1->v2;
    a->f2 = enrac2(f1->f3, f1->v3, f1->f4);
    f1->type = type2fils;

    return a;
}

Arb234 rem2g(Arb234 a){
    a->type = type4fils;
    a->f4 = a->f3;
    a->f3 = a->f2;
    a->f2 = enrac2(a->fils1->f3,
                      a->fils1->val3,
                      a->fils1->f4
    )
    a->val3 = a->val2;
    a->val1 = a->fils1->val2;
    a->fils1->type = type2fils
}

Arb234 ins(S x, Arb234 a){
    if(est_vide(a)) return enrac2(anouv(), x, anouv());
    if(a->type == type4fils){
        Arb234 f2 = enrac2(a->f3, a-> v3, a->f4);
        a->type = type2fils;
        Arb234 res = enrac2(a, a->v2, f2);
        ins(x,res);
    }
    if(est_feuille(a)) return ins_feuille(x,a);
    else {
        if(a->type == type3fils){
            if(x > a ->v2){
                if(a->f3->type4fils){
                    a = new2d(a);
                    a = ins_aux(x, a);
                } else {
                    a = ins(x,a->f3);
                }
            } else if
        }
    }
}

```
