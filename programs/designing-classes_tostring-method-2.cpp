string toString() const {
  char buffer[100];
  snprintf(buffer, sizeof(buffer), "%02d:%02d:%04.1f\n", hour, minute, second);
  return string(buffer);
}