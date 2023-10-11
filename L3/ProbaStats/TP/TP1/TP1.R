setwd("/home/axel/Cours/L3/ProbaStats/TP/TP1")

## Vecteurs --------
vec1 <- c(3,4.6,1.2,-7.8)
vec2 <- -4:7
vec3 <- seq(2,18,3)
vec4 <- rep(vec2,3)
vec5 <- c(vec1,vec2,vec3)
couleur <- c("vert","rouge","jaune","bleu")
vec6 <- c(T,F,T,T,F)
length(vec3)
mode(vec3)
length(vec6)
mode(vec6)
length(vec5)
mode(vec5)
mat1 <- matrix(vec4,ncol=3,byrow=TRUE)
mat2 <- matrix(vec4,ncol=4,byrow=FALSE)

## Fichier texte -------
tab <- read.table("table.txt",header=TRUE)

## Créer un data frame ------
taille<-c(1.40,1.67,1.90,2.14)
poids<-c(54,62,75,91)
danger<-c("extrême","fort","fort","faible")
nom<-c("a","b","c","d")
tab1<-data.frame(taille,poids,danger,row.names=nom)

## Partie oiseaux ------
oiseaux<-read.csv("oiseaux.csv",header=TRUE,dec=",",sep=";")
mean(oiseaux$AIL)
var(oiseaux$AIL)
sd(oiseaux$AIL)
median(oiseaux$AIL)
quantile(oiseaux$HUM,probs = c(0.8))
quantile(oiseaux$BRE,probs = c(0.845))
