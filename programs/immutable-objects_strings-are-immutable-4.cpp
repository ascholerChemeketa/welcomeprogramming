string text = "Computer Science is fun!";
size_t pos = text.find("Computer Science");
if (pos != string::npos) {
  text.replace(pos, string("Computer Science").length(), "CS");
}
