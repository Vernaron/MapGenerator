#include "MapFuncs.h"
int main(){
  HelloWorld("Hello World!");
  debugMark(----------DEBUG START----------)
  Empire* finArr=makeEmps(30, 100, 100, 579);
  debugMark(---------------PRINTING ALL ARRAYS---------------)
   
    std::cout<<indent(2)<<roundUp(1.5f)<<std::endl;
    for(int i=0;i<30;i++){
	finArr[i].printEmpire();
	}
    std::cout<<std::endl;
    return 0;
}
