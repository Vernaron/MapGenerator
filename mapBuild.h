#ifndef MAPBUILD_H
#define MAPBUILD_H
#include <iostream>
#include <string>
#include <random>
#include <time.h>
class Town{
	int x;
	int y;
	int tsize;
	char faction;
	std::string name;
	public:
	void buildTown(int size, int seed, int nx, int ny, char nfaction);
};
class Empire{
	int ID;
	char faction;
	int numTowns;
	Town* TownArr;
	int radius;
	std::string name;
	public:
	void buildEmpire(int esize, int seed, int mx, int my, char faction);
};
std::string** makeArr(int numEmpires, int x, int y, int seed);
std::string indent(int numindent);
std::string genName(int faction, int seed);
#endif
