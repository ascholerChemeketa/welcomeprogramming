RegularPolygon(int nsides, int radius, string color) {
  // validate the arguments
  if (nsides < 3) {
    throw invalid_argument("invalid nsides");
  }
  if (radius <= 0) {
    throw invalid_argument("invalid radius");
  }
  if (color.empty()) {
    throw invalid_argument("invalid color");
  }

  // the rest of the method is omitted
}