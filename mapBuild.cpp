#include "mapBuild.h"
std::string indent(int numindent){
	std::string output="\n";
	for(int i=0;i<numindent;i++){
		output+="  ";
	}
	return output;
}
std::string genName(int faction, int seed){
	const int elfSize=1;
	const int dwarfSize=1;
	const int dragonBSize=1;
	const int humanSize=1;
	const int orcSize=1;
	int orcListFirst[orcSize];
	switch(faction){
	case 'h'://human
	break;
	case 'e'://elf
	break;
	case 'd'://dwarf
	break;
	case 'o'://orc
	break;
	case 'D'://dragonborn
	break;
	default:
	return "Unknown";
	}
	return "Unknown";
}
std::string** makeArr(const int numEmpires, int x, int y, int seed){
	srand(time(NULL));//the seed is a number which is used to generate things. To prevent division by 0 errors, a 0 seed is explicitly rejected
	if(seed==0||seed>=999999){
		std::cout<<"Invalid Seed, please try again"<<std::endl;
		return NULL;
	}
	if(seed==NULL){//if a seed is not provided, a random one is generated
	seed=rand()%999999;
	}
	Empire* empArr=new Empire[numEmpires];
	for(int i=0;i<numEmpires;i++){
	}
	return NULL;
}
void Empire::buildEmpire(int esize, int seed, int mx, int my, char faction){
	name=genName(faction, seed);
	numTowns=seed%(esize/3);
	int TownAvSize=numTowns/15;
	TownArr=new Town[numTowns];
	int tseed;
	int tx;
	int ty;
	for(int i=1;i<=numTowns;i++){
		tseed=seed+(31*i*(seed/RAND_MAX));
		tx=(tseed%esize)-(mx/2);// generates the x location of the town
		int sizeratio=esize/10;
		tx+= tx==0 ? sizeratio: (tx>-sizeratio&&tx<sizeratio ? tx*sizeratio:0);//if tx is 0, adds ten, if tx is less then sizeratio away from center, multiplies by sizeratio
		ty=((tseed*7/3)%esize)-(my/2);
		ty+= ty==0 ? sizeratio: (ty>-sizeratio&&ty<sizeratio ? ty*sizeratio:0);
		TownArr[i-1].buildTown(tseed%TownAvSize, tseed, tx, ty, faction);
	}
	
}
void Town::buildTown(int size, int seed, int nx, int ny, char nfaction){
		tsize=seed%size;
		x=nx;
		y=ny;
		faction=nfaction;
		name=genName(faction, seed);
		
}