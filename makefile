CC = g++
CFLAGS = -g -Wall

MapMain:mapBuild.o MapFuncs.o MapMain.o 
	$(CC) $(CFLAGS) mapBuild.o MapFuncs.o MapMain.o -o MapMain
	./MapMain
mapBuild.o:mapBuild.cpp mapBuild.h
	$(CC) $(CFLAGS) mapBuild.cpp -c
MapFuncs.o:MapFuncs.cpp MapFuncs.h mapBuild.h
	$(CC) $(CFLAGS) MapFuncs.cpp -c
MapMain.o:MapMain.cpp MapFuncs.h
	$(CC) $(CFLAGS) MapMain.cpp -c
