#ifndef SWIMMINGPOOL_H_CPP_SWIMMINGPOOL_H
#define SWIMMINGPOOL_H_CPP_SWIMMINGPOOL_H
#include <string>

using namespace std;
class SwimmingPool {
private:
    string adress;
    int volume;
    int max_number_of_visitors;


protected:
    int number_of_months_when_open;
    string type;

public:
    int size;
    string condition;

    SwimmingPool();
    SwimmingPool(string adress, int volume, int max_number_of_visitors, int number_of_months_when_open, string type, int size, string condition);
    ~SwimmingPool();
    string getAdress();
    int getVolume();
    int getMax_number_of_visitors();
    int getNumber_of_months_when_open();
    int getSize();
    string getCondition();
    string getType();
    void printSwimmingPoolInfo();
};



#endif