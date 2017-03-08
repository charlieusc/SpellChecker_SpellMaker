//
//  Helper.hpp
//
//  Created by YangJialin on 2/11/17.
//  Copyright © 2017 YangJialin. All rights reserved.
//

#ifndef Helper_hpp
#define Helper_hpp

#include <random>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

#endif /* Helper_hpp */
using namespace std;

string getPattern(string word);
string createRandomWordFromPattern(string pattern);
bool isVow(char c);
string removeDupicate(string word);
size_t levenshteinDistance(const string &s1, const string &s2);
