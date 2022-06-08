#ifndef MAPBUILD_H
#define MAPBUILD_H
#include <iostream>
#include <string>
#include <random>
#include <time.h>
//#define PRINTDEBUG 
#define debug(x) 
#define debugMark(x)
#ifndef PRINTDEBUG 
#define debug(x) std::cout<<#x<<":"<<x<<std::endl; 
#define debugMark(x) std::cout<<"--"<<#x<<"--"<<std::endl; 
#endif
#define NUM_FACTIONS 5 //defines number of factions for entire program
class Town{
	int ID;
	int x;
	int y;
	int tsize;
	char faction;
	std::string name;
	public: 
	void buildTown(int size, int seed, int nx, int ny, char nfaction);
	void printTown();
};
class Empire{
	int x;
	int y;
	int ID;
	char faction;
	int numTowns;
	Town* TownArr;
	int radius;
	std::string name;
	public:
	void buildEmpire(int esize, int seed, int mx, int my, char nfaction);
	void printEmpire();
};
Empire* makeEmps(int numEmpires, int x, int y, int seed);
std::string indent(int numindent);
std::string genName(int faction, int seed);
#endif
