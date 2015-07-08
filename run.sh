#!/usr/bin/env bash

# run script for running the word count

# I'll execute my programs, with the input directory tweet_input and output the files in the directory tweet_output
./build/words_tweeted ./tweet_input/tweets.txt ./tweet_output/ft1.txt
./build/median_unique ./tweet_input/tweets.txt ./tweet_output/ft2.txt



