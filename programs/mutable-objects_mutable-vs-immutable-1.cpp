/* This Java code demonstrates a quirk of string comparison in Java.  While s1
 * and s2 appear to be the same, the == operator compares references, not
 * content, and in this case, the compiler optimizes "Hi, " + "Mom!" resulting
 * in both s1 and s2 referencing the same string literal in the string pool.
 * This behavior might not always be consistent and is not recommended for
 * comparing string content. Using .equals() method is the standard and safe way
 * of comparing string content. */
#include <iostream>
#include <string>

int main() {
  string s1 = "Hi, Mom!";
  string s2 = "Hi, " + "Mom!";
  if (s1 == s2) {
    cout << "s1 and s2 are the same" << endl;
  }
  return 0;
}