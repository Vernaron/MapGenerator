CC = g++
CFLAGS = -g 

MapMain:MapMain.o MapFuncs.o mapBuild.o
	$(CC)  MapMain.o MapFuncs.o mapBuild.o -o MapMain 
	./MapMain
MapMain.o:MapMain.cpp MapFuncs.h
	$(CC) MapMain.cpp -c  
MapFuncs.o: MapFuncs.cpp MapFuncs.h mapBuild.h
	$(CC) MapFuncs.cpp -c 
mapBuild.o: mapBuild.h mapBuild.cpp
	$(CC) mapBuild.cpp -c
