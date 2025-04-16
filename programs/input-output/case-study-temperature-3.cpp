
<cline> double maxDiff = 0;</cline>
<cline> string town = "???";</cline>
<cline> while (!inFile.eof()) {</cline>
<cline>  // Read in the data</cline>
<cline>  string city, state;</cline>
<cline>  double janTemp, julyTemp, rainfall;</cline>
<cline>  inFile >> city >> state >> janTemp >> julyTemp >> rainfall;</cline>
<cline>  if (inFile.fail()) {</cline>
<cline>    break; // Exit the loop if we could not read</cline>
<cline>  }</cline>
<cline></cline>
<cline>  double tempDiff = julyTemp - janTemp;</cline>
<cline> }</cline>
<cline>}