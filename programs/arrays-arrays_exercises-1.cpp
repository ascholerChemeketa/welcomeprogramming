Conway(const string& path) {
  ifstream file(path);
  // Check if the file was opened successfully
  if (!file.is_open()) {
    throw runtime_error("Could not open file");
  }
  // Rest of the code omitted.
}