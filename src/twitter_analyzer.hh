#ifndef TWITTER_ANALYZER_HH
#define TWITTER_ANALYZER_HH

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
<<<<<<< HEAD
#include <vector>
#include <map>
#include <unordered_set>
=======
#include <set>
#include <map>
>>>>>>> 78869f7e26c718923a60ac65e771787630560043

class twitter_analyzer {
public:
  twitter_analyzer(const std::string &infile_name = "../tweet_input/tweets.txt") {
    infile.open(infile_name);
    if (!infile.is_open()) {
      std::cerr << "Fail to open " << infile_name << std::endl;
      exit(1);
    }
  }

  twitter_analyzer(const twitter_analyzer &other) {}
  twitter_analyzer & operator = (const twitter_analyzer &other) {
    return *this;
  }
  twitter_analyzer(twitter_analyzer &&other) {}
  twitter_analyzer & operator = (twitter_analyzer &&other) {
    return *this;
  }

  virtual ~twitter_analyzer() {
    infile.close();
  }

  void words_tweeted(const std::string &outfile_names);

  void median_unique(const std::string &outfile_names);

private:
  std::ifstream infile;
};

#endif	// TWITTER_ANALYZER_HH
