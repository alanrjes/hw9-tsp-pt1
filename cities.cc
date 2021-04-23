#include "cities.hh"
#include <cmath>

Cities::Cities(std::vector<coord_t> map) {  // constructor
  map_ = map;
}

std::istream& Cities::operator>> (std::istream& is) {
  int len = map_.size();
  for (int i=0; i<len; i++) {
    coord_t coords = map_[i];
    is>> std::get<0>(coords)>> std::get<1>(coords);
  }
  return is;
}

std::ostream& Cities::operator<< (std::ostream& os) {
  int len = map_.size();
  for (int i=0; i<len; i++) {
    coord_t coords = map_[i];
    os<< std::get<0>(coords)<< std::get<1>(coords);
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
    double subdist = std::sqrt(std::pow((std::get<0>(coords) - std::get<0>(prevcoords)), 2) + std::pow((std::get<1>(coords) - std::get<1>(prevcoords)), 2));
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
  return Cities(nmap);
}

permutation_t Cities::random_permutation(unsigned len) {
  //
}
