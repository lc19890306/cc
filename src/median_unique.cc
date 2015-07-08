#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <set>
#include <map>

int main() {
  std::ifstream infile("../tweet_input/tweets.txt");
  std::ofstream outfile1("../tweet_output/ft1.txt");
  std::ofstream outfile2("../tweet_output/ft2.txt");
  std::string line;
  std::size_t total(0), counter(0);
  // double avg;
  std::map<std::string, std::size_t> word_tweeted;
  while (getline(infile, line)) {
    ++counter;
    // std::cout << line << std::endl;
    std::istringstream entry(line);
    std::string word;
    std::set<std::string> unique_words;
    while (entry >> word) {
      auto it(word_tweeted.find(word));
      if (it == word_tweeted.end())
	word_tweeted.insert(it, std::make_pair(word, 1));
      else
	++it->second;
      // std::cout << word << std::endl;
      // auto it(unique_words.find(word));
      // if (it == unique_words.end())
      // 	unique_words.insert(it, word);
      // else
      // 	unique_words.erase(it);
      unique_words.insert(word);
    }
    total += unique_words.size();
    outfile2 << std::setiosflags(std::ios::fixed) 
	     << std::setprecision(2) 
	     << static_cast<double>(total) / counter 
	     << std::endl;
  }
  outfile2.close();
  for (auto &&pair : word_tweeted)
    outfile1 << std::setw(40)
	     << std::left
	     << pair.first
	     << pair.second
	     << std::endl;
  outfile1.close();

  return 0;
}
