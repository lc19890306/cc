#ifndef MEDIAN_UNIQUE_HH
#define MEDIAN_UNIQUE_HH

#include <fstream>
#include <iomanip>
#include <sstream>
#include <set>

void median_unique(std::ifstream &infile) {
  std::ofstream outfile("../tweet_output/ft2.txt");
  std::string line;
  std::size_t total(0), counter(0);

  while (std::getline(infile, line)) {
    ++counter;
    std::istringstream entry(line);
    std::string word;
    std::set<std::string> unique_words;
    while (entry >> word)
      // std::cout << word << std::endl;
      // auto it(unique_words.find(word));
      // if (it == unique_words.end())
      // 	unique_words.insert(it, word);
      // else
      // 	unique_words.erase(it);
      unique_words.insert(word);
    total += unique_words.size();
    outfile << std::setiosflags(std::ios::fixed) 
	    << std::setprecision(2) 
	    << static_cast<double>(total) / counter 
	    << std::endl;
  }
  outfile.close();
}

#endif	// MEDIAN_UNIQUE_HH
