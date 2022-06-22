#include "mapBuild.h"
int sq(int num){
return num*num;
}
int zoomIn(int min, int max, int numIters, int seed){
  if (!numIters){
    return min;
  }
    seed=(int)(((float)seed/(seed*seed))*2.3);
    return (seed%2? zoomIn(min, max/2, numIters-1, seed):zoomIn(max/2, max, numIters-1, seed));
}
int roundUp(auto x){
	int a = (int)x>=x ? (int)x : (int)x+1;
	return a;
}
int increment(int limit, int incrementNum){
	debugMark(Increment Function)
	int returnValue=0;
	for (int i=0;i<incrementNum;i++){
	returnValue+=1;
	debug(returnValue)
	debug(limit)
	returnValue= returnValue>limit ? 0 : returnValue;
	}
	return returnValue;
}
std::string indent(int numindent){
	std::string output="\n";
	for(int i=0;i<numindent;i++){
		output+="     ";
	}
	return output;
}
std::string genName(int faction, int seed){//depending on the faction+seed, gives a combination of a first+last half of faction
	/*const int elfSize=1;
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
	int xLim= x*.05;
	int yLim=y*.05;
	int eSize;
	int eSeed;
	int eMx;
	int eMy;
	for(int i=1;i<=numEmpires;i++){
		debugMark(Debugging Empire Generation Loop)
		  eSeed=(seed+(14*i))%99999;
		debug(eArea)
		debug(i)
		debug(numEmpires)
		eSize=eArea/(50*numEmpires);
		debug(eSeed)
		debug(seed)
		  eMx=xLim+(((x-(2*xLim))/(numEmpires/2))*(i%(numEmpires/2)))+((i*sq(eSeed))%((x-(2*xLim))/(numEmpires/2)));
		eMy=yLim+(i*sq(eSeed))%(y-(2*yLim));
		debug(eSize)
		empArr[i-1].buildEmpire(eSize,eSeed,eMx,eMy,FACTION_LIST[(i-1)%NUM_FACTIONS],x,y);
	}
	return empArr;
}
void Empire::buildEmpire(int esize, int seed, int mx, int my, char nfaction, int xMax, int yMax){
	faction=nfaction;
	debugMark(Debugging Empire)
	name=genName(faction, seed);
	numTowns=esize/5;
	int TownAvSize=numTowns/esize;
	TownAvSize+= TownAvSize ? 0 : 1;
	radius=esize;
	ID=seed;
	x=mx;
	y=my;
	TownArr=new Town[numTowns];
	int tseed;
	int tx;
	int ty;
	double angle;
	int sizeratio;
	const auto PI = std::acos(-1);
	for(int i=1;i<=numTowns;i++){
		debugMark(Debugging Town Loop)
		tseed=((seed+(7*i))%seed)%99999;
		angle=(sq(i)*sq(tseed));
		tx=x+(radius*std::cos(angle*(PI/180)))-1;// generates the x location of the town
		sizeratio=esize/numTowns;
		ty=y+(radius*std::sin(angle*(PI/180)))-1;
		debug(tx)
		debug(ty)
		tx= tx==x ? x+1:tx;
		ty= ty==y ? y+1:ty;
		tx= tx<1? 1 : tx>xMax-2 ? xMax-2 : tx;
		ty= ty<1? 1 : ty>yMax-2 ? yMax-2 : ty;
		
		TownArr[i-1].buildTown(tseed%TownAvSize, tseed, tx, ty, faction, xMax, yMax);
	}
	
}
void Town::buildTown(int size, int seed, int nx, int ny, char nfaction, int xMax, int yMax){
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
void Town::setTown(char** printedMap){
	printedMap[y][x]='T';
}
void Empire::setEmpire(char** printedMap, int xMax, int yMax){
	float xR;
	float yR;
	const auto pi=std::acos(-1);
	int radTemp=1;	
	bool hitBorder;
	for(int i=1;i<360;i+=5){
		radTemp=1;
		hitBorder=false;
		int j=1;
		while (j<=radius){
			xR=(float)x+((float)j*std::cos((float)i*(pi/180)));
			yR=(float)y+((float)j*std::sin((float)i*(pi/180)));
			if (!hitBorder){
				radTemp = j;
			}
			if (xR<1||yR<1||xR>xMax-2||yR>yMax-2){
				break;
			}
			if(printedMap[(int)yR][(int)xR]=='`'){
				hitBorder=true;
			}
			printedMap[(int)yR][(int)xR]=' ';
			j+=1;
		}
		if(!hitBorder){
			xR=(float)x+((float)radius*std::cos((float)i*(pi/180)));
			yR=(float)y+((float)radius*std::sin((float)i*(pi/180)));
			if (!(xR<1)&&!(yR<1)&&!(xR>xMax-2)&&!(yR>yMax-2)){
				printedMap[(int)yR][(int)xR]='`';
			}
		}
		else{
			xR=(float)x+((float)((radius+radTemp)/2)*std::cos((float)i*(pi/180)));
			yR=(float)y+((float)((radius+radTemp)/2)*std::sin((float)i*(pi/180)));
			std::cout<<indent(1)<<"Made It";
			if (!(xR<1)&&!(yR<1)&&!(xR>xMax-2)&&!(yR>yMax-2)){
				continue;
			}
			printedMap[(int)yR][(int)xR]='`';
		}
	}
	

	printedMap[y][x]='E';
	for(int i=0;i<numTowns;i++){
		TownArr[i].setTown(printedMap);
	}
}
void Empire::setToken(char** printedMap, int xMax, int yMax){
	printedMap[y][x]='E';
	for(int i=0;i<numTowns;i++){
		TownArr[i].setTown(printedMap);
	}
}