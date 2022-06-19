#include "MapFuncs.h"
int main(){
  HelloWorld("Hello World!");
  debugMark(----------DEBUG START----------)
  Empire* finArr=makeEmps(6, 100, 100, 579);
  debugMark(---------------PRINTING ALL ARRAYS---------------)
  for(float i=0.0f;i<5.0f;i+=0.1){
  std::cout<<i<<" "<<roundUp(i)<<std::endl;
  }
  for(int i=0;i<6;i++){
	finArr[i].printEmpire();
  }
    return 0;
}
