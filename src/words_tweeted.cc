#include "twitter_analyzer.hh"

void
twitter_analyzer::words_tweeted(const std::string &outfile_name) {
  std::map<std::string, std::size_t> word_times;
  std::size_t word_base(100000), tmp_file_base(64), tmp_file_counter(0);
  std::string word;
  std::vector<std::string> tmp_file_names;

  // Preprocess input data and create initial temp files,
  // each of which stores words of at most word_base
  while (infile >> word) {
    ++word_times[word];
    if (0 == word_times.size() % word_base)
      create_tmp_file(tmp_file_counter++, word_times, tmp_file_names);
  }
  if (!word_times.empty())
    create_tmp_file(tmp_file_counter++, word_times, tmp_file_names);

  // Recursively process a group of temp files of at most tmp_file_base
  std::size_t i;
  for (i = 0; i + tmp_file_base < tmp_file_names.size(); i += tmp_file_base) {
    std::string tmp_file_name(create_tmp_file_name(tmp_file_counter++));
    tmp_file_names.push_back(tmp_file_name);
    std::ofstream tmp_file(tmp_file_name, std::ios::binary);
    merge_tmp_files(i, i + tmp_file_base, tmp_file_names, tmp_file);
    tmp_file.close();
  }
  std::ofstream outfile(outfile_name);
  merge_tmp_files(i, tmp_file_names.size(), tmp_file_names, outfile);
  outfile.close();

  // Reset input stream
  infile.clear();
  infile.seekg(0, std::ios_base::beg);
}

void
twitter_analyzer::create_tmp_file(const std::size_t &tmp_file_counter,
				  std::map<std::string, std::size_t> &word_times,
				  std::vector<std::string> &tmp_file_names) {
  std::string tmp_file_name(create_tmp_file_name(tmp_file_counter));
  tmp_file_names.push_back(tmp_file_name);
  std::ofstream tmp_file(tmp_file_name, std::ios::binary);
  for (auto &&pair : word_times)
    tmp_file << std::setw(40)
	     << std::left
	     << pair.first
	     << pair.second
	     << std::endl;
  tmp_file.close();
  std::map<std::string, std::size_t>().swap(word_times);
}

std::string
twitter_analyzer::create_tmp_file_name(const std::size_t &tmp_file_counter) {
  std::string tmp_file_name("tmp_");
  tmp_file_name += std::to_string(tmp_file_counter);
  tmp_file_name += ".dat";
  return tmp_file_name;
}

void
twitter_analyzer::merge_tmp_files(const std::size_t &begin,
				  const std::size_t &end,
				  std::vector<std::string> &tmp_file_names,
				  std::ostream &os) {
  std::map<std::string, std::vector<std::size_t> > input_records;
  std::vector<std::ifstream *> tmp_inputs;
  std::map<std::string, std::size_t> word_times;
  std::string word;
  std::size_t num;

  // Collect the smallest word tweeted from each temp file
  for (std::size_t i = begin; i != end; ++i)
    tmp_inputs.push_back(new std::ifstream(tmp_file_names[i]));
  for (std::size_t i = 0; i != tmp_inputs.size(); ++i) {
    if (*tmp_inputs[i] >> word >> num) {
      word_times[word] += num;
      input_records[word].push_back(i);
    }
  }

  // Write the smallest word into new file and remove it from the record
  // Collect the second smallest word from the tmp files where the previous
  // smallest word have been collected
  // Recursively until all words are collected
  while (!word_times.empty()) {
    os << std::setw(40)
       << std::left
       << word_times.begin()->first
       << word_times.begin()->second
       << std::endl;
    word_times.erase(word_times.begin());
    for (auto &&i : input_records.begin()->second) {
      if (*tmp_inputs[i] >> word >> num) {
	word_times[word] += num;
	input_records[word].push_back(i);
      }
      else {
  	tmp_inputs[i]->close();
  	delete tmp_inputs[i];
      }
    }
    input_records.erase(input_records.begin());
  }
}
