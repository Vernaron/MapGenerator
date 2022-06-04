CC = gcc
CFLAGS = -g 

MapMain:MapMain.o MapFuncs.o
	$(CC)  MapMain.o MapFuncs.o -o MapMain 
	MapMain
MapMain.o:MapMain.cpp MapFuncs.h
	$(CC) MapMain.cpp MapFuncs.h -c $(CFLAGS) MapMain.o
MapFuncs.o: MapFuncs.cpp MapFuncs.h
	$(CC) MapFuncs.cpp MapFuncs.h -c $(CFlAgS) MapFuncs.o

