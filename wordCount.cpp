//
// Created by Raunak Anand on 2019-04-22.
//

#include "wordCount.h"
#include <iostream>
#include "StringFunctions.h"
#include <vector>

typedef std::map<std::string, int>WordCount;


void countWords(std::istream& in, WordCount& wordCount){ // adds each word in the file to the dictionary
  std::string s;
  while (in >> s){
    lowerInPlace(s); // lower space all the words
    stripInPlace(s, R"(,.:;\"|\\!@#$%^&*()_+-=[]{}<>?/~`'")"); // removal of special characters
    if(s != "a" && s != "an" && s != "and" && s != "in" && s != "is" && s != "it" && s != "the"){
      ++wordCount[s]; // if word exists then instances increases by one
    }
  }
}
std::multimap<int, std::string>reverseMap(std::map<std::string, int>WordCount) {
  // creation of a multimap[instances] -> word
  std::multimap<int, std::string>newMap;

  for(auto i = WordCount.begin(); i != WordCount.end(); ){
    newMap.insert(std::pair<int, std::string>(i->second, i->first));
    WordCount.erase(i++); // erase initial map
  }
  return newMap;
}

std::map<int, std::vector<std::string> >finalMap(std::multimap<int, std::string>newMap){
  std::map<int, std::vector<std::string> >WordDict;
  // map of vectors
  for(auto& element: newMap){
    WordDict[element.first].push_back(element.second); // words with same word count(key)
  }                                                    // added to the same vector

  return WordDict; // final map
}

void printCount(std::map<int, std::vector<std::string> >WordDict, int nums){ // print final map
  int numbering = 1;
  for(auto i = WordDict.rbegin(); i != WordDict.rend(); i++ ){ // to print in descending order
    const auto& count = (*i).first;
    const auto& words = (*i).second;
    std::cout << numbering << ".)"  << " These words appeared " << count << " times: {";
    for(auto x = words.begin(); x != words.end(); x++){
      if(x == words.end()-1){ // CSIF Tutor Kiran Bhadury
        std::cout << *x ;
      } else {
        std::cout << *x << ", ";
      }
    }
    std::cout << "}\n";
    numbering++;
    if(numbering > nums){ // CSIF Tutor Kiran Bhadury
      break;
    }
  }
}

