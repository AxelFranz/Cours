## TD2

Addresse IP : \<localisateur>\<id_machine>

### Exercice 3

### Question 2

| taille | @réseau       |
| ------ | ------------- |
| 50k    | 33.88.0.0/16  |
| 50k    | 33.89.0.0/16  |
| 2000   | 33.90.0.0/21  |
| 2000   | 33.90.8.0/21  |
| 2000   | 33.90.16.0/21 |
| 300    | 33.90.24.0/23 |
| 300    | 33.90.26.0/23 |
| 2      | 33.90.28/30   |
| 2      | 33.90.28.4/30 |
| 2      | 33.90.28.4/30 |

### Question 3

| Hôte                             | @IP          | @Broadcast   | Route                                                                                               |
| -------------------------------- | ------------ | ------------ | --------------------------------------------------------------------------------------------------- |
| A                                | 33.90.24.3   | 33.90.25.255 | 33.90.24.0/23 joignable localement<br/> 33.90.16.0.21 via 22.90.25.254<br/>default via 33.90.25.254 |
| B                                | 33.90.16.1   | 33.90.23.255 | 33.90.16.0/21 joignable localement                                                                  |
| R3 interface avec le réseau de B | 33.90.23.254 | 33.90.23.255 | 33.90.16.0/21<br/>33.90.28.0<br/>33.90.24.0/23 via 33.90.28.1                                       |

Table de routage de R2

| @dest                | next hop        |
| -------------------- | --------------- |
| 33.90.28.4/3         | local           |
| 33.90.28.8           | local           |
| 33.90.24.0/23        | R2(@IP de (5))  |
| 33.88.0.0/16         | R2(@IP de (5))  |
| 33.90.0.0/21         | R2(@IP de (5))  |
| 33.89.0.0/16         | R2(@IP de (5))  |
| 33.90.8.0/21         | R3(@IP de (4))  |
| 33.90.16.0/21        | R3(@IP de (4))  |
| 33.90.26.0/23        | R3(@IP de (4))  |
| RE_R3(33.90.28.0/30) | R2(interface 5) |

Version EXAMEN

| @dest | next hop |
| ----- | -------- |
| L1    | local    |
| L2    | local    |
| L3    | local    |
| L4    | local    |
| L5    | R3       |
| L6    | R3       |
| L7    | R3       |
| R1-R2 | local    |
| R2-R3 | local    |
| R1_R3 | R1       |
