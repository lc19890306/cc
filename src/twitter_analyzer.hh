#ifndef TWITTER_ANALYZER_HH
#define TWITTER_ANALYZER_HH

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_set>

#include <cstdio>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstdlib>
#include <unistd.h>

class twitter_analyzer {
public:
  twitter_analyzer(const std::string &infile_name = "../tweet_input/tweets.txt") {
    infile.open(infile_name);
    if (!infile) {
      std::cerr << "Fail to open " << infile_name << std::endl;
      exit(1);
    }
  }

  virtual ~twitter_analyzer() noexcept {}

  void words_tweeted(const std::string &outfile_name);

  void median_unique(const std::string &outfile_name);

private:
  twitter_analyzer(const twitter_analyzer &other) {}
  twitter_analyzer & operator = (const twitter_analyzer &other) {
    return *this;
  }
  twitter_analyzer(twitter_analyzer &&other) {}
  twitter_analyzer & operator = (twitter_analyzer &&other) {
    return *this;
  }

  // For median_unique
  std::size_t total_unique(const std::string &line);

  // For words_tweeted
  void create_tmp_file(const std::size_t &tmp_file_counter,
		       std::map<std::string, std::size_t> &word_times,
		       std::vector<std::string> &tmp_file_names);

  // For words_tweeted
  std::string create_tmp_file_name(const std::size_t &tmp_file_counter);

  // For words_tweetd
  void merge_tmp_files(const std::size_t &begin,
		       const std::size_t &end,
		       std::vector<std::string> &tmp_file_names,
		       std::ostream &os);

  std::ifstream infile;
};

#endif	// TWITTER_ANALYZER_HH
