#include "twitter_analyzer.hh"

void
twitter_analyzer::median_unique(const std::string &outfile_names) {
  std::ofstream outfile(outfile_names);
  std::string line;
  std::size_t total(0), counter(0);
  std::unordered_set<std::string> unique_words;
  std::vector<double> median_data;

  while (std::getline(infile, line)) {
    ++counter;
    std::istringstream entry(line);
    std::string word;
    while (entry >> word)
      unique_words.insert(word);
    total += unique_words.size();
    unique_words.clear();
    median_data.push_back(static_cast<double>(total) / counter );
  }
  for (auto &&median : median_data)
    outfile << std::setiosflags(std::ios::fixed) 
    	    << std::setprecision(2) 
    	    << median
    	    << std::endl;
  outfile.close();

  // Reset input stream
  infile.clear();
  infile.seekg(0, std::ios_base::beg);
}
