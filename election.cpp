
#include "election.hpp"
#include "vote.hpp"
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>

using namespace std;

void election::add_vote(const vote &v){
    votes.push_back(v);
}

int  election::vote_count() const{
    return votes.size();
}

void election::eliminate(candidate c){
    for(auto &v: votes){
        v.discard(c);
    }

      
}

vector<pair<candidate,int> > election::ranked_candidates() const{
    map<candidate,int> collection;
    candidate c;
    for(const vote &v: votes){
        if(v.first_preference() > 0){
        c = v.first_preference();
        collection[c]++;
        }
    }
    vector<pair<candidate,int>> list(collection.cbegin(), collection.cend());
    sort(list.begin(), list.end(),
    [](const pair<candidate,int> &a, const pair<candidate,int> &b)
    {return a.second > b.second;});
    return list;
}


election read_votes(istream &in){
    election election1;
    string line;
    
    
    while(getline(in,line)){
        stringstream s(line);
        vector<candidate> input;
        string str;
        while(getline(s,str,' ')){
            input.push_back(stoi(str));
        }
        election1.add_vote(input);
    }
 
    

    return election1;
}




