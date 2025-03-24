    string message = "Hello there!";
    string part1 = message.substr(0, 5);  //first 5 characters
    string part2 = message.substr(11);    //everything at or after index 11
  
    // assign message a new value based on combining part1 and part2
    message = part1 + part2;