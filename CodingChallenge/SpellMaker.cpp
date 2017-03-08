//
//  SpellMaker.cpp
//
//  Created by YangJialin on 2/11/17.
//  Copyright © 2017 YangJialin. All rights reserved.
//

#include "SpellMaker.hpp"

SpellMaker:: SpellMaker() {
    
}

vector<string> SpellMaker:: creatWrongWords(int n) {
    vector<string> ret;
    int len = dict.size();
    // This will ensure a really randomized number by help of time.
    srand(time(0));
    for (int i=0; i<n; i++) {
        int index = rand() % len;
        string word = dict[index];
        string pattern = getPattern(word);
        string wrongWord = createRandomWordFromPattern(pattern);
        ret.push_back(wrongWord);
    }
    return ret;
}

void SpellMaker:: setDict() {
    ifstream myFile;
    string word;
    myFile.open("/usr/share/dict/words");
    if (myFile.is_open()) {
        //cout << "open successful" << endl;
        while(getline(myFile, word)) {
            dict.push_back(word);
        }
        myFile.close();
    } else {
        cout << "File not found!" << endl;
        exit(0);
    }
}


