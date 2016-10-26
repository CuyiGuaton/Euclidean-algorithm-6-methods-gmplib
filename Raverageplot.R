tabla=read.table("Informe/plot/a2.txt")
names=tabla$V1
mean=tabla$V2
min=tabla$V3
max=tabla$V4

library(ggplot2) 
ggplot(tabla, aes(x=names, y=mean)) + 
  geom_errorbar(aes(ymin=min, ymax=max), width=.5) +
  
  geom_point()
