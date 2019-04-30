#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "wordCount.h"


int main(int argc, char** argv) {
  int nums;
  if (argc < 2){ // checking if argument has been given
    exit(1);  // if not given, exit
  }
  std::ifstream inFile(argv[1]);
  if (argc < 3){
    nums = 10;
  } else {
    nums = std::stoi(argv[2]); // arguments in string, so convert to integers
  }


  if(!inFile){
    exit(1);
  }
  WordCount wcount;
  countWords(inFile, wcount); // creation of map
  std::multimap<int, std::string>CountWord = reverseMap(wcount); // creation of multimap

  std::map<int, std::vector<std::string> >WordDict = finalMap(CountWord); // creation of final map

  printCount(WordDict, nums); // print
  return 0;
}
