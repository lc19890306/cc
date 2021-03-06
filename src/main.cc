#include "main.hh"

namespace po = boost::program_options;

int
main(int argc, char **argv) {
  try {
    std::string infile_name;
    std::vector<std::string> outfile_names({"ft1.txt", "ft2.txt"});

    po::options_description usage("");
    // Add options
    po::options_description desc("Options");
    desc.add_options()
      ("version", "display version")
      ("help", "display help information")
      ("words-tweeted", po::value<std::string>(&outfile_names[0]), "calculate the total number of times each word has been tweeted")
      ("median-unique", po::value<std::string>(&outfile_names[1]), "calculate the median number of unique words per tweet")
      ("input-file", po::value<std::string>(&infile_name), "set input file");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);    

    // Query version
    if (vm.count("version")) {
      display_version();
      return 1;
    }

    // Need help?
    if (vm.count("help") || vm.empty()) {
      std::cout << "Usage: twitter_analyzer [options]" << std::endl;
      std::cout << desc << std::endl;
      return 1;
    }

    // Set input file
    if (vm.count("input-file"))
      infile_name = vm["input-file"].as<std::string>();

    // Prepare the analyzer
    twitter_analyzer ta(infile_name);

    // Query words tweeted
    if (vm.count("words-tweeted"))
      ta.words_tweeted(outfile_names[0]);

    // Query the median number of unique words per tweet
    if (vm.count("median-unique"))
      ta.median_unique(outfile_names[1]);

  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}

