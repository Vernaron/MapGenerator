#include "mapBuild.h"

std::string indent(int numindent){
	std::string output="\n";
	for(int i=0;i<numindent;i++){
		output+="     ";
	}
	return output;
}
std::string genName(int faction, int seed){//depending on the faction+seed, gives a combination of a first+last half of faction
	const int elfSize=1;
	const int dwarfSize=1;
	const int dragonBSize=1;
	const int humanSize=1;
	const int orcSize=1;
	int orcListFirst[orcSize];
	/*switch(faction){
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
	}*/
	return "Unknown";
}
Empire* makeEmps(const int numEmpires, int x, int y, int seed){
	char FACTION_LIST[NUM_FACTIONS] = {'h','e','d','o','D'};
	srand(time(NULL));//the seed is a number which is used to generate things. To prevent division by 0 errors, a 0 seed is explicitly rejected
	if(seed==0||seed>=999999){
		std::cout<<"Invalid Seed, please try again"<<std::endl;
		return NULL;
	}
	if(seed==NULL){//if a seed is not provided, a random one is generated
	seed=rand()%999999;
	}
	//debug(numEmpires)
	Empire* empArr=new Empire[numEmpires];
	int eArea= x*y;
	int eSize;
	int eSeed;
	int eMx;
	int eMy;
	for(int i=1;i<=numEmpires;i++){
		debugMark(Debugging Empire Generation Loop)
		eSeed=(seed+(7*i))%seed;
		debug(eArea)
		debug(i)
		debug(numEmpires)
		eSize=eArea%(numEmpires+i)+1;
		debug(eSeed)
		debug(seed)
		eMx=x-(x/eSeed);
		eMy=y-(y/(eSeed+eMx));
		debug(eSize)
		empArr[i-1].buildEmpire(eSize,eSeed,eMx,eMy,FACTION_LIST[(i-1)%NUM_FACTIONS]);
	}
	return empArr;
}
void Empire::buildEmpire(int esize, int seed, int mx, int my, char nfaction){
	faction=nfaction;
	debugMark(Debugging Empire)
	name=genName(faction, seed);
	numTowns=seed%esize+1;
	//debug(seed)
	//debug(esize)
	//debug(numTowns)
	int TownAvSize=numTowns/esize;
	TownAvSize+= TownAvSize ? 0 : 1;
	radius=esize;
	ID=seed;
	x=mx;
	y=my;
	//debug(mx)
	//debug(my)
	TownArr=new Town[numTowns];
	debug(TownArr)
	int tseed;
	int tx;
	int ty;
	for(int i=1;i<=numTowns;i++){
		debugMark(Debugging Town Loop)
		//debug(i)
		tseed=seed+(7*i);
		debug(tseed)
		tx=mx+ ((tseed%i)-mx);// generates the x location of the town
		//debug(tx)
		int sizeratio=esize/numTowns;
		//debug(sizeratio)
		tx+= tx==0 ? sizeratio: (tx>-sizeratio&&tx<sizeratio ? tx*sizeratio:0);//if tx is 0, adds ten, if tx is less then sizeratio away from center, multiplies by sizeratio
		debugMark(After Tx Ternary)
		ty=my+((tseed*7/3)%i-my);
		ty+= ty==0 ? sizeratio: (ty>-sizeratio&&ty<sizeratio ? ty*sizeratio:0);
		tx = tx<0 ? 0:tx;
		ty = ty<0 ? 0:ty;
		//debugMark(After Ty Ternary)
		//debug(tseed)
		//debug(TownAvSize)
		TownArr[i-1].buildTown(tseed%TownAvSize, tseed, tx, ty, faction);
		//debugMark(Town Build)
	}
	
}
void Town::buildTown(int size, int seed, int nx, int ny, char nfaction){
		size += size ? 0 : 1;
		debugMark(Debugging Town)
		ID=seed;
		debug(seed)
		debug(size)
		tsize=seed%size;
		x=nx;
		y=ny;
		faction=nfaction;
		name=genName(faction, seed);
		
}
void Empire::printEmpire(){
	std::cout<<"\n"<<"id:"<<ID
	<<indent(1)<<"x:"<<x
	<<indent(1)<<"y:"<<y
	<<indent(1)<<"faction:"<<faction
	<<indent(1)<<"number of towns:"<<numTowns
	<<indent(1)<<"size:"<<radius;
		for(int i=0;i<numTowns;i++){
			TownArr[i].printTown();
		}
}
void Town::printTown(){
	std::cout<<"\n"<<indent(2)<<"id:"<<ID
	<<indent(3)<<"x:"<<x
	<<indent(3)<<"y:"<<y
	<<indent(3)<<"size:"<<tsize;
}