//
//  main.cpp
//
//  Created by YangJialin on 2/10/17.
//  Copyright © 2017 YangJialin. All rights reserved.
//

#include "SpellChecker.hpp"
#include "SpellMaker.hpp"


using namespace std;
int main(int argc, const char * argv[]) {
    SpellChecker myChecker;
    myChecker.setDict();
    SpellMaker myMaker;
    myMaker.setDict();
    vector<string> wrongWords = myMaker.creatWrongWords(10);
    for(string wrongWord : wrongWords) {
        cout << wrongWord << ": ";
        cout << myChecker.giveSuggestion(wrongWord) << endl;
    }
    myChecker.checking();
    return 0;
}

