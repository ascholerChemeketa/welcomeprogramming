// add the index to 'a' to get a number, cast that as a character
char curChar = static_cast<char>('a' + i);
cout << curChar << ": " << counts.at(i) << endl;