#ifndef DISPLAY_VERSION_HH
#define DISPLAY_VERSION_HH

#include <string>
#include <iostream>

const std::string VERSION("1.0");

void display_version() {
  std::cout << VERSION << std::endl;  
}

#endif	// DISPLAY_VERSION_HH
