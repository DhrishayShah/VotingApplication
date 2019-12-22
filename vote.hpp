
#ifndef vote_hpp
#define vote_hpp

#include <stdio.h>
#include <vector>
typedef unsigned int candidate;
class vote{
      std::vector<candidate> preferences;
    
public:
    
    vote(const std::vector<candidate> &prefs);
    
    bool spent() const;

    candidate first_preference() const;

    void discard(candidate c);
    
    int size_of_vector() const;

};

#endif /* vote_hpp */
