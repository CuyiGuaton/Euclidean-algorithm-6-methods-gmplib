for(i in 2:5){

  tabla=read.table(paste("Informe/plot/a",toString(i) , ".txt",sep = ""))
  names=factor(tabla$V1, levels = tabla$V1)
  mean=tabla$V2
  min=tabla$V3
  max=tabla$V4
  
  library(ggplot2) 
  plots <-ggplot(tabla, aes(x=names, y=mean)) + 
    geom_errorbar(aes(ymin=min, ymax=max), width=.5) +  geom_point() + ggtitle(paste("Algoritmo ",i,sep="")) +
    labs(x="bits",y="Tiempo en nanosegundos") +
    theme_bw() +
    theme(axis.line = element_line(colour = "black"),
          panel.grid.major = element_blank(),
          panel.grid.minor = element_blank(),
          panel.border = element_blank(),
          panel.background = element_blank()) 
  ggsave(plots,filename=paste("Informe/plot/a",i,".png",sep=""))

}