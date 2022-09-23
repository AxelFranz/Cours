# I. Logique bi-valuée

3. a) P v -P
   
   b) A
   
   c) $P\land\neg P$
   
   d) Leur négation est satifiable

4. Vrai car si $\exist I,I(G)=1 \text{ ou }\exist I,I(H)=1 \text{. Dans ce cas, }I(G\lor H)=1$.
   
   Faux car $A\land\neg A$ est valide mais pas ses opérandes

5. On va prouver que tous les connecteurs de base peuvent être faits avec
   
   $A\lor B≡A\Rightarrow B$
   
   $A\land B ≡ \neg(\neg A\lor\neg B) ≡ \neg(A\Rightarrow\neg B)$ 

        $A\Leftrightarrow B=\neg((A\Rightarrow B)\Rightarrow\neg(B\Rightarrow A))$

(P v Q => R v S) AND (R v S => P v Q)

(NON(P v Q => NON(R v S))) AND (NON(R v S => NON(P v Q)))
