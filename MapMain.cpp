#include "MapFuncs.h"
int main(){
	int numEmps;
	int x;
	int y;
	int seed;
	std::ifstream settings;
	std::ofstream outputMap;
	settings.open("mapconfig.txt");
	settings>>numEmps>>x>>y>>seed;
	settings.close();
	debugMark(----------DEBUG START----------)
	char** printedMap;
	printedMap=new char*[y];
	for(int i=0;i<y;i++){
		printedMap[i]=new char[x];
	}
	Empire* finArr=makeEmps(numEmps, x, y, seed);
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){//outer is y, inner is x
			printedMap[i][j] = j==0||j==x-1  ?  '|' : (i==0||i==y-1  ?  '-' : '#' );
		}
	}
	for(int i=0;i<numEmps;i++){
	finArr[i].setEmpire(printedMap, x, y);
	}
	for(int i=0;i<numEmps;i++){
	finArr[i].setToken(printedMap, x, y);
	}
	outputMap.open("mapPrinted.txt");
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){//outer is y, inner is x
			outputMap<<printedMap[i][j];
		}
		outputMap<<'\n';
	}
	outputMap.close();
  return 0;
}
