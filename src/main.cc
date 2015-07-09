#include "main.hh"

namespace po = boost::program_options;

int main(int argc, char **argv) {
  std::string infile_name;
  std::vector<std::string> outfile_names({"ft1.txt", "ft2.txt"});

  po::options_description desc("Allowed options");
  desc.add_options()
    ("version", "display version")
    ("help", "produce help message")
    ("words-tweeted", po::value<std::string>(&outfile_names[0]), "calculate the total number of times each word has been tweeted")
    ("median-unique", po::value<std::string>(&outfile_names[1]), "calculate the median number of unique words per tweet")
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

  twitter_analyzer ta(infile_name);

  if (vm.count("words-tweeted"))
    ta.words_tweeted(outfile_names[0]);

  if (vm.count("median-unique"))
    ta.median_unique(outfile_names[1]);

  return 0;
}

