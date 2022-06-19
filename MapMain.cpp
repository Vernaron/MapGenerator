#include "MapFuncs.h"
int main(){
  HelloWorld("Hello World!");
  debugMark(----------DEBUG START----------)
  Empire* finArr=makeEmps(6, 100, 100, 579);
  debugMark(---------------PRINTING ALL ARRAYS---------------)
   
    std::cout<<indent(2)<<roundUp(1.5f)<<std::endl;
    for(int i=0;i<6;i++){
	finArr[i].printEmpire();
	}
    return 0;
}
