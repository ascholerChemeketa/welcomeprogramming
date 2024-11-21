string name1 = "Alan Turing";
string name2 = "Ada Lovelace";
int diff = name1.compare(name2);
if (diff < 0) {
  cout << "name1 comes before name2.\n";
} else if (diff > 0) {
  cout << "name2 comes before name1.\n";
} else {
  cout << "The names are the same.\n";
}