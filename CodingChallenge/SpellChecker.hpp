//
//  SpellChecker.hpp
//
//  Created by YangJialin on 2/11/17.
//  Copyright © 2017 YangJialin. All rights reserved.
//

#ifndef SpellChecker_hpp
#define SpellChecker_hpp

#include "Helper.hpp"

#endif /* SpellChecker_hpp */
using namespace std;

class SpellChecker {
public:
    SpellChecker();
    void checking();
    void setDict();
    string giveSuggestion(string word);
    
private:
    map<string, vector<string> > dict;
    bool inDict(string pattern);
    
};

