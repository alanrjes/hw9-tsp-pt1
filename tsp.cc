#include "cities.hh"
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
  char* filename = argv[1];  // if the user gives multiple file arguments, just use the first
  std::ifstream ifile(filename);  // file stream to read
  std::ofstream ofile("shortest.tsv");  // file stream to write

  // read file
  Cities cities;
  ifile >> cities;

  int itercount = 1000;
}
