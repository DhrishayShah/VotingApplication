#include "vote.hpp"
#include <vector>
#include <algorithm>


using namespace std;

vote::vote(const vector<candidate> &prefs): preferences(prefs) {}


bool vote::spent() const{

    if(preferences.size() == 0){
        return true;
    }else{
        return false;
    }
}
candidate vote::first_preference() const{
    
    candidate first = 0;
    
    if(vote::spent() == false){
       first =  preferences[0];
    }
    return first;
}

void vote::discard(candidate c){
    
    auto end = remove(preferences.begin(),preferences.end(), c);
    preferences.erase(end,preferences.end());

}


    
    

