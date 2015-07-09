#include "twitter_analyzer.hh"

void
twitter_analyzer::words_tweeted(const std::string &outfile_names) {
  std::ofstream outfile(outfile_names);
  std::string line;
  std::map<std::string, std::size_t> word_tweeted;

  while (std::getline(infile, line)) {
    std::istringstream entry(line);
    std::string word;
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
    }
  }
  for (auto &&pair : word_tweeted)
    outfile << std::setw(40)
	    << std::left
	    << pair.first
	    << pair.second
	    << std::endl;
  outfile.close();

  // Reset input stream
  infile.clear();
  infile.seekg(0, std::ios_base::beg);
}
