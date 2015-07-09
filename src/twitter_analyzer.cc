#include "median_unique.hh"
#include "words_tweeted.hh"
#include "display_version.hh"

#include <fstream>
#include <iostream>
#include <vector>

#include <boost/program_options.hpp>
// #include <boost/exception/all.hpp>
// typedef boost::error_info<struct tag_my_info,int> my_info;
namespace po = boost::program_options;

int main(int argc, char **argv) {
  std::string infile_name("../tweet_input/tweets.txt");

  po::options_description desc("Allowed options");
  desc.add_options()
    ("version", "display version")
    ("help", "produce help message")
    ("median-unique", "calculate the median number of unique words per tweet")
    ("words-tweeted", "calculate the total number of times each word has been tweeted")
    ("input-file", po::value<std::string>(&infile_name), "set input file, default [../tweet_input/tweets.txt]");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);    

  if (vm.count("version")) {
    display_version();
    return 1;
  }

  if (vm.count("help")) {
    std::cout << desc << std::endl;
    return 1;
  }

  if (vm.count("input-file"))
    infile_name = vm["input-file"].as<std::string>();

  std::ifstream infile;

  if (vm.count("median-unique")) {
    infile.open(infile_name);
    median_unique(infile);
    infile.close();
  }

  if (vm.count("words-tweeted")) {
    infile.open(infile_name);
    words_tweeted(infile);
    infile.close();
  }

  // std::cout << desc << std::endl;

  return 0;
}
