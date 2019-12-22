#ifndef election_hpp
#define election_hpp

#include <stdio.h>
#include <vector>
#include <utility>
#include "vote.hpp"

class election{
    std::vector<vote> votes;
    public:
        void add_vote(const vote &v);

        int  vote_count() const;

        void eliminate(candidate c);

        std::vector<std::pair<candidate,int> > ranked_candidates() const;
};

election read_votes(std::istream &in);


#endif
