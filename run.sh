#!/usr/bin/env bash

# run script for running the word count

# I'll execute my programs, with the input directory tweet_input and output the files in the directory tweet_output
./build/twitter_analyzer --words-tweeted=./tweet_output/ft1.txt --median-unique=./tweet_output/ft2.txt --input-file=./tweet_input/tweets.txt
