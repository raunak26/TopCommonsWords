//
// Created by Raunak Anand on 2019-04-22.
//

#ifndef TOPCOMMONWORDS__WORDCOUNT_H_
#define TOPCOMMONWORDS__WORDCOUNT_H_

#include <string>
#include <map>
#include <vector>


typedef std::map<std::string, int>WordCount; // map declaration

std::multimap<int, std::string>reverseMap(std::map<std::string, int>WordCount); // creation of multimap from map

void countWords(std::istream& in, WordCount& wordCount); // creation of first map

std::map<int, std::vector<std::string> >finalMap(std::multimap<int, std::string> newMap); // creation of map of vectors
                                                                                          // using multimap

void printCount(std::map<int, std::vector<std::string>>WordDict, int nums); // print final map



#endif //TOPCOMMONWORDS__WORDCOUNT_H_
