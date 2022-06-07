#include "MapFuncs.h"
int main(){
  HelloWorld("Hello World!");
  debugMark(----------DEBUG START----------)
  Empire* finArr=makeEmps(3, 100, 100, 579);
  debugMark(---------------PRINTING ALL ARRAYS---------------)
  for(int i=0;i<3;i++){
	finArr[i].printEmpire();
  }
    return 0;
}
