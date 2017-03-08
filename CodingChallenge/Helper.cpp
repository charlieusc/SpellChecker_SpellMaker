//
//  Helper.cpp
//
//  Created by YangJialin on 2/11/17.
//  Copyright © 2017 YangJialin. All rights reserved.
//

#include "Helper.hpp"

string getPattern(string word) {
    //change word to lower case
    for (int i=0; i<word.size(); i++) {
        word[i] = tolower(word[i]);
    }
    
    //change all vowels to '*' & remove duplicates
    for (int i=0; i<word.size(); i++) {
        if (isVow(word[i])) {
            word[i] = '*';
        }
    }
    return removeDupicate(word);
}


string createRandomWordFromPattern(string pattern) {
    string word;
    string vows = "aeiou";
    //adding some duplicates
    for (int i=0; i<pattern.size();i++) {
        for (int j=0; j<rand() % 3 + 1; j++) {
            word+=pattern[i];
        }
    }
    //replace all '*' in the word to random vowels
    //capitalize letters in the word randomly
    for (int i=0; i<word.size(); i++) {
        if (word[i] == '*') {
            word[i] = vows[rand() % 5];
        }
        if (rand() % 2 > 0) {
            word[i] = toupper(word[i]);
        }
    }
    

    return word;
}

string removeDupicate(string word) {
    for (int i=0; i<word.size(); i++) {
        if (i > 0 && word[i] == word[i-1]) {
            word.erase(i, 1);
            i--;
        }
    }
    return word;
}
bool isVow(char c) {
    string vows = "aeiou";
    for (char v : vows) {
        if (c == v) {
            return true;
        }
    }
    return false;
}

size_t levenshteinDistance(const string &s1, const string &s2) {
    const size_t m(s1.size());
    const size_t n(s2.size());
    
    if( m==0 ) return n;
    if( n==0 ) return m;
    
    size_t *costs = new size_t[n + 1];
    
    for( size_t k=0; k<=n; k++ ) costs[k] = k;
    
    size_t i = 0;
    for ( auto it1 = s1.begin(); it1 != s1.end(); ++it1, ++i )
    {
        costs[0] = i+1;
        size_t corner = i;
        
        size_t j = 0;
        for ( auto it2 = s2.begin(); it2 != s2.end(); ++it2, ++j )
        {
            size_t upper = costs[j+1];
            if( *it1 == *it2 )
            {
                costs[j+1] = corner;
            }
            else
            {
                size_t t(upper<corner?upper:corner);
                costs[j+1] = (costs[j]<t?costs[j]:t)+1;
            }
            
            corner = upper;
        }
    }
    
    size_t result = costs[n];
    delete [] costs;
    
    return result;
}
