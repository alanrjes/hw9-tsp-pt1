#include "cities.hh"
#include <cmath>  // std::sqrt
#include <algorithm>  // std::random_shuffle

std::istream& operator>> (std::istream& is, Cities& cities) {
  Cities::coord_t coords;
  int i = 0;
  while (is>> coords.first>> coords.second) {
    cities.map_[i] = coords;
    i++;
  }
  return is;
}

std::ostream& operator<< (std::ostream& os, Cities& cities) {
  int len = cities.map_.size();
  for (int i=0; i<len; i++) {
    Cities::coord_t coords = cities.map_[i];
    os<< coords.first<< coords.second;
  }
  return os;
}

double Cities::total_path_distance(const permutation_t& ordering) const {
  int len = ordering.size();
  coord_t firstcoords = map_[ordering[0]];
  coord_t prevcoords;
  double dist;  // sum of distance

  for (int i=1; i<=len; i++) {
    coord_t coords;
    if (i == len) {  // if it's the last iteration
      coords = firstcoords;  // find returning distance to the first city
    }
    else {
      coords = map_[ordering[i]];  // coords of next city in permutation, adjusted by ordering index
    }
    double subdist = std::sqrt(std::pow((coords.first - prevcoords.first), 2) + std::pow((coords.second - prevcoords.second), 2));
    dist += subdist;
    prevcoords = coords;
  }
  return dist;
}

Cities Cities::reorder(const permutation_t& ordering) const {
  int len = ordering.size();
  std::vector<coord_t> nmap(len);
  for (int i=0; i<len; i++) {
    coord_t coords = nmap[ordering[i]];
    nmap[i] = coords;
  }
  Cities ncities;
  ncities.map_ = nmap;
  return ncities;
}

Cities::permutation_t Cities::random_permutation(unsigned len) {
  permutation_t ordering{0, 1, 2, 3, 4, 5, 6, 7, 8};
  std::random_shuffle(ordering.begin(), ordering.end());
  return ordering;
}
