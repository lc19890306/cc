#include "twitter_analyzer.hh"

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void
twitter_analyzer::median_unique(const std::string &outfile_name) {
  std::ofstream outfile(outfile_name);
  std::string line;
  std::size_t counter(0);
  double median(0);

  // Read each line from the input file and calculate the total number
  // of unique words, then calculate the median and write it into file
  while (std::getline(infile, line)) {
    ++counter;
    median -= (median - total_unique(line)) / counter;
    outfile << std::setiosflags(std::ios::fixed) 
    	    << std::setprecision(2) 
    	    << median
    	    << std::endl;
  }
  outfile.close();

  // Reset input stream
  infile.clear();
  infile.seekg(0, std::ios_base::beg);
}

std::size_t
twitter_analyzer::total_unique(const std::string &line) {
  std::unordered_set<std::string> unique_words;
  std::istringstream entry(line);
  std::string word;
  while (entry >> word)
    unique_words.insert(word);  
  return unique_words.size();
}
