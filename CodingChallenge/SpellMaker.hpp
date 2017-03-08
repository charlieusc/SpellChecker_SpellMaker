//
//  SpellMaker.hpp
//
//  Created by YangJialin on 2/11/17.
//  Copyright © 2017 YangJialin. All rights reserved.
//

#ifndef SpellMaker_hpp
#define SpellMaker_hpp

#include "Helper.hpp"

#endif /* SpellMaker_hpp */

using namespace std;

class SpellMaker {
public:
    SpellMaker();
    void setDict();
    vector<string> creatWrongWords(int n);
private:
    vector<string> dict;

};
