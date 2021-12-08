# TD5 : Codage des données



# 1. Représentation informatique de N et Z

## 1.1 Changement de base
| Base 10 | Base 2   | Base 16 |
| ------- | -------- | ------- |
| 14      | 111      | E       |
| 124     | 1111100  | 7C      |
|         | 100101   |         |
|         | 11001011 |         |
|         |          | 19B     |
|         |          | A35     |



## 1.2 Codage des entiers signés et non-signés

### 1.2.1 Codage

```c
unsigned char c1 = 37;  // Entier non signé => 8 bits et son code est 00100101
signed   char c2 = 37;  // Entier signé => 8 bits et son code est 00100101
signed   char c3 = -14; // Entier négatif signé => 8 bits + complément à 2 et son code est 11110010
unsigned int  i1 = 411; //
		 int  i2 = 411; //
         int  i3 = -203;//
```

### 1.2.2 Décodage



### 1.2.3 Promotion / Troncature

```c
unsigned char c4 = 37;  // 00100101
unsigned int i4  = c4;  // 0000 0000 0000 0000 0000 0000 00100101
signed 	 char c5 = -14; // 11110010
         int i5  = c5;  // 1111 1111 1111 1111 1111 1111 11110010
unsigned int i6  = 411; // 0000 0000 0000 0000 0000 0001 10011011
unsigned char c6 = i6;  // 10011011
         int i7  = -203;// 1111 1111 1111 1111 1111 1111 00110101
signed   char c7 = i7;  // 00110101
```



### 1.2.4 Limites



## 1.3 Arithmétique des entiers signés et non-signés

```c
unsigned char uc1 = 124, uc2 = 37, uc3;
signed char   sc1 = 14, sc2 = 37, sc3;
			  uc3 = uc1 + uc2;
			  sc3 = sc1 - sc2;
```

Réaliser le calcul en binaire



# 2. Représentation informatique de R

## 2.1 Changement de base

| Base 10   | Base 2   |
| --------- | -------- |
| 14.3125   |          |
| 37.390625 |          |
|           | 1001.101 |
|           | 1.01101  |



## 2.2 Codage des flottants IEEE 754 binary32

### 2.2.1 Codage

```c
float f1 = 0.31250;    ==> 0,0101 en base 2 
float f2 = -124.40625; ==> 

```



### 2.2.2 Décodage











