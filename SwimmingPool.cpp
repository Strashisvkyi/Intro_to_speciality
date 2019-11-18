#include <iostream>
#include <string>
#include "SwimmingPool.h"

using namespace std;
   SwimmingPool::SwimmingPool(string adress, int volume, int max_number_of_visitors, int number_of_months_when_open, string type, int size, string condition){
    this->adress = adress;
    this->volume = volume;
    this->max_number_of_visitors = max_number_of_visitors;
    this->number_of_months_when_open = number_of_months_when_open;
    this->type = type;
    this->size = size;
    this->condition = condition;

    return;

}
 SwimmingPool::SwimmingPool() {

}
     SwimmingPool::~SwimmingPool() {

}
    string SwimmingPool::getAdress() {
    return adress;
}
    int SwimmingPool::getVolume() {
    return volume;
}
    int SwimmingPool::getMax_number_of_visitors() {
    return max_number_of_visitors;
}
    int SwimmingPool::getNumber_of_months_when_open() {
    return number_of_months_when_open;
}
    int SwimmingPool::getSize() {
    return size;
}
    string SwimmingPool::getType() {
    return type;
}

    string SwimmingPool::getCondition() {
    return condition;
}
 void SwimmingPool::printSwimmingPoolInfo() {
    cout<<"adress="<<adress<<endl;
    cout<<"volume="<<volume<<endl;
    cout<<"size="<<size<<endl;
    cout<<"max_number_of_visitors="<<max_number_of_visitors<<endl;
    cout<<"number_of_months_when_open="<<number_of_months_when_open<<endl;
    cout<<"Type="<<type<<endl;
    cout<<"condition="<<condition<<endl<<endl;
 }


