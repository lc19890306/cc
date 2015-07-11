# Insight Data Engineering - Coding Challenge

This project is written in C++11, with the help of Boost library (1.58.0).

Platform: Mac OS X, Intel i5 processor, 4 Gb memory, clang++-3.5 compiler
Compatible platforms: all Linux variants with g++-4.3 or later (clang++-3.3 or later)

All source code files are put in src folder. Just "make" it to obtain the final executive which will be put in build folder (Install Boost 1.58.0 before that).

The run.sh script executes the executive to read input files from tweet_input folder and then produce expected outputs in tweet_output folder.

Possible scalability issues regarding these two problems:

    To calculate the total number of times each word has been tweeted, I need to deal with large input data file. What I did is to create a number of temp files and recursively merge a group of them into a new temp file until the only and last file is obtained.

    To calculate the median number of unique words per tweet and update this median as tweets come in, I need to deal with possible big number in the calculation. In order to avoid summation and multiplication, which may yield big number, I used the mathematical calculation shown as follows:

	new_median = old_median - (old_median - current_number) / total_number.
