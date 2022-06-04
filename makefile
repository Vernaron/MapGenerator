CC = g++
CFLAGS = -g 

MapMain:MapMain.o MapFuncs.o
	$(CC)  MapMain.o MapFuncs.o -o MapMain 
	./MapMain
MapMain.o:MapMain.cpp MapFuncs.h
	$(CC) MapMain.cpp -c  
MapFuncs.o: MapFuncs.cpp MapFuncs.h
	$(CC) MapFuncs.cpp -c 

