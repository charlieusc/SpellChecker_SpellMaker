# Spell Checker & Spell Maker

This is a project I developed for coding challenge

## Challenge Description

Write a program that reads a large list of English words (e.g. from /usr/share/dict/words on a Unix system) into memory, and then reads words from stdin, and prints either the best spelling suggestion or "NO SUGGESTION" if no suggestion can be found. The program should print ">" as a prompt before reading each word, and should loop until killed.

Your solution should be faster than O(n) per word checked, where n is the length of the dictionary. That is to say, you can't scan the dictionary every time you want to spellcheck a word.

```
For example:
> sheeeeep
sheep
> peepple
people
> sheeple
NO SUGGESTION
```
The class of spelling mistakes to be corrected is as follows:

```
Case (upper/lower) errors: "inSIDE" => "inside"
Repeated letters: "jjoobbb" => "job"
Incorrect vowels: "weke" => “wake"
Any combination of the above types of error in a single word should be corrected (e.g. "CUNsperrICY" => "conspiracy”).
```

If there are many possible corrections of an input word, your program can choose one in any way you like. It just has to be an English word that is a spelling correction of the input by the above rules.

Final step: Write a second program that *generates* words with spelling mistakes of the above form, starting with correctly spelled English words. Pipe its output into the first program and verify that there are no occurrences of "NO SUGGESTION" in the output.

## Solution

### SpellChecker

1) Get all the words from the library(/usr/share/dict/words) and calculate its pattern in this way: people -> p * p l *; butt -> b * t (change all vowels to * and reduce all duplicates in the word).

2) Group the words that have the same pattern and map them using a map<string, vector<string>> Dict, for example: sh*p -> ["sheep", "ship", "shop", ...]

```
For setting up the Dict, it takes O(n*m) time, n is the number of words in the library, m is the length of the longest word in the library.
```

3) Calculate the input word's pattern and find if Dict has that pattern. If Dict contains that pattern, we get the words array using that pattern as the key. Then, we output a word from the array that has minimum Levenshtein Distance(https://en.wikipedia.org/wiki/Levenshtein_distance) with the input word. Otherwise, output "NO SUGGESTION".

```
For giving the suggestion, it takes O(p+m) time, p is the largest amount of words that share the same pattern, m is the length of your input word. Because the number of words that share the same pattern are quite small, so O(p+m) < O(n).
```

### SpellMaker

1) Pick n words randomly in the library.

2) For each chosen word: change the word to the pattern mentioned above; duplicate letters and '*' in the word randomly; replace all '*' in the word to random vowels; capitalize letters in the word randomly.

3) Pipe all the generated "wrong word" to SpellChecker and print both "wrong word" and SpellChecker's suggestion.

## Getting Started

This project was developed in Xcode and also could be run in Unix/ Linux system.

### Prerequisites

To run this project, C++11 is needed for compiling.

### Installing

To run this program in terminal, just go to the folder that contains the main.cpp and type these lines in terminal below and hit enter:

```
g++ -c main.cpp
g++ -c Helper.cpp
g++ -c SpellChecker.cpp
g++ -c SpellMaker.cpp
g++ -omy_program main.o Helper.o SpellChecker.o SpellMaker.o
./my_program
```

## Running the tests

Follow the steps above, the program should be running and print out 10 'generated' wrong words followed by the correct word in the library. Then a ">" would prompt and you can type in your input for testing. Type "_quit_" to exit the program:

```
drrOUpull: drupel
cccEpphhulLIaPppUotThy: cephalopathy
nNNOaunnggRipPhuottIc: nongraphitic
iEUnnnffFarrRSWwWERnNn: unforsworn
SUplLLATtiIuVvvIeO: suppletive
phHullIURoPpoeU: phalarope
poRRuIUPPHHyYysSeICcCuol: paraphysical
wWUsSsTeEwuEYy: westaway
PiaunnOITtaIeSs: pionnotes
DdiGGRrrieddDiedD: degraded
> sheeeeep
sheep
> peeple
people
> sheeple
NO SUGGESTION
> inSIDE
inside
> jjoobbb
job
> weke
woke
> CUNsperrICY
conspiracy
> _quit_
Thank you for checking!
```
