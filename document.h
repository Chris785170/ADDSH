
#include <iostream>
#include <vector>
using namespace std;
class document
{

public:
    string name;
    int id;
    int license_limit;
document(string name_, int id_, int licence_limit_){
    name = name_;
    id = id_;
    license_limit = licence_limit_;
}
};



