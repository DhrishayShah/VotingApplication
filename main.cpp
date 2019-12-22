#include "vote.hpp"
#include "election.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    fstream in("votes.txt");
    
    election main_election = read_votes(in);
    
    int round = 1;
    
    while(true){
        int count = main_election.vote_count();
        
        cout<<"Round "<<round++<<": "<<count<<" votes\n";
        
        cout<<"First preferences:\n";
        
        vector<pair<candidate,int>> results = main_election.ranked_candidates();
        
        for(auto &x: results){
            
            cout<<"  Candidate "<<x.first<<": "<<x.second<<'\n';
            
        }
        
        if(results[0].second >= (count/2)){
            cout<<"Candidate "<<results.front().first<<" is selected.\n\n";
            break;
        }else{
            cout<<"Candidate "<<results.back().first<<" is eliminated.\n\n";
            main_election.eliminate(results.back().first);
        }
    }
    
    
    
    return 0;
}
