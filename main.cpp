/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <string>

#include "SwimmingPool.h"

int main() {
    SwimmingPool first("Green street,4",400,30,9,"children's",70,"perfect");
    SwimmingPool second("Long street,104",800,130,12,"adult's",90,"bad");
    SwimmingPool third("Wall street,15",4100,90,2,"sports",150,"satisfactory");
    first.printSwimmingPoolInfo();
    second.printSwimmingPoolInfo();
    third.printSwimmingPoolInfo();
    return 0;
}









