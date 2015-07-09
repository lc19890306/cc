#include "twitter_analyzer.hh"

void
twitter_analyzer::median_unique(const std::string &outfile_names) {
  std::ofstream outfile(outfile_names);
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

  // Reset input stream
  infile.clear();
  infile.seekg(0, std::ios_base::beg);
}
