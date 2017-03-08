//
//  SpellChecker.cpp
//
//  Created by YangJialin on 2/11/17.
//  Copyright © 2017 YangJialin. All rights reserved.
//

#include "SpellChecker.hpp"

SpellChecker:: SpellChecker() {

}

void SpellChecker:: setDict() {
    ifstream myFile;
    string word;
    myFile.open("/usr/share/dict/words");
    if (myFile.is_open()) {
        //cout << "open successful" << endl;
        while(getline(myFile, word)) {
            string pattern = getPattern(word);
            dict[pattern].push_back(word);
        }
        myFile.close();
    } else {
        cout << "File not found!" << endl;
        exit(0);
    }
}
bool SpellChecker:: inDict(string pattern) {
    if (dict.find(pattern) != dict.end()) {
        return true;
    } else {
        return false;
    }
}
void SpellChecker:: checking() {
    string word;
    while (true) {
        cout << "> ";
        cin >> word;
        //if input is "_quit_", exit the program
        if (word == "_quit_") {
            cout << "Thank you for checking!" << endl;
            break;
        }
        //check if word is in the dictionary
        //if not, can we give a suggstion word?
        if (inDict(word)) {
            cout << word << endl;
        } else {
            cout << giveSuggestion(word) << endl;
        }
    }
}
string SpellChecker:: giveSuggestion(string word) {
    
    string ret = "NO SUGGESTION";
    string pattern = getPattern(word);
    vector<string> wordsGroup;
    
    if (dict.find(pattern)!=dict.end()) {
        wordsGroup = dict[pattern];
    } else {
        return ret;
    }
    
    
    //change word to lower case
    for (int i=0; i<word.size(); i++) {
        word[i] = tolower(word[i]);
    }
    
    int lDis = INT_MAX;
    for(string s : wordsGroup) {
        int tDis = (int)levenshteinDistance(s, word);
        if (lDis >= tDis) {
            lDis = tDis;
            ret = s;
            if (lDis == 0) {
                return ret;
            }
        }
    }
    return ret;
}
