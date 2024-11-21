for (int count : counts) {
    if (count != 0 &amp;&amp; count != 2) {
        return false;  // not a doubloon
    }
}
return true;  // is a doubloon