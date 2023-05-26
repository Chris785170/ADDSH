#include "DocumentManager.h"


void DocumentManager::addDocument(string name, int id, int license_limit){ // constant time to add to back of vector unless vector needs to be resized
    document a = document(name,id, license_limit);
    thing.push_back(a);
};

void DocumentManager::addPatron(int patronID){ // logarithmic time but this short coming is made up for in the searchign algorithmn
    patrons.insert(patronID);
};

int DocumentManager::search(string name_){ // complexity is O(n) on average with bestcase being O(1) this is Okay snice adding is so fast
    for (int i = 0; i<thing.size(); i++){
        if (thing[i].name == name_){
            return thing[i].id;
        }
    }
    return 0;
};

bool DocumentManager::borrowDocument(int docid, int patronID){ 
    for (int i = 0; i<thing.size(); i++){
        if (thing[i].id == docid){
            if (thing[i].license_limit > 0 && patrons.count(patronID) > 0){ // nlog(n) because of for loop and patrons.count is log(n)
                thing[i].license_limit = thing[i].license_limit -1;
                return true;
            }
        }
    }
    return false;

};  // returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)

void DocumentManager::returnDocument(int docid, int patronID){
    if ( patrons.count(patronID) > 0){ // log(n) if patron does not belong to the libary
        return;
    }
    for (int i = 0; i<thing.size(); i++){
        if (thing[i].id == docid){
            // nlog(n) because of for loop and patrons.count is log(n)
            thing[i].license_limit = thing[i].license_limit +1;
            
        }
    }
};
