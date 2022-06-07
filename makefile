CC = g++
CFLAGS = -g -Wall

MapMain:MapMain.o MapFuncs.o mapBuild.o
	$(CC) $(CFLAGS) MapMain.o MapFuncs.o mapBuild.o -o MapMain 
	./MapMain
MapMain.o:MapMain.cpp MapFuncs.h
	$(CC) $(CFLAGS) MapMain.cpp -c  
MapFuncs.o: MapFuncs.cpp MapFuncs.h mapBuild.h
	$(CC) $(CFLAGS) MapFuncs.cpp -c 
mapBuild.o: mapBuild.h mapBuild.cpp 
	$(CC) $(CFLAGS) mapBuild.cpp -c
