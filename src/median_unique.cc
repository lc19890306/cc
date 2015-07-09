#include "twitter_analyzer.hh"

void
twitter_analyzer::median_unique(const std::string &outfile_names) {
  std::ofstream outfile(outfile_names);
  std::string line;
  std::size_t total(0), counter(0);
<<<<<<< HEAD
  std::unordered_set<std::string> unique_words;
  std::vector<double> median_data;
=======
>>>>>>> 78869f7e26c718923a60ac65e771787630560043

  while (std::getline(infile, line)) {
    ++counter;
    std::istringstream entry(line);
    std::string word;
<<<<<<< HEAD
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
=======
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
>>>>>>> 78869f7e26c718923a60ac65e771787630560043
  outfile.close();

  // Reset input stream
  infile.clear();
  infile.seekg(0, std::ios_base::beg);
}
