string cardset = "cardset-oxymoron";
string suits = "cdhs";

for (int suit = 0; suit <= 3; ++suit) {
  char c = suits[suit];
  for (int rank = 1; rank <= 13; ++rank) {
    string s = string::format("%s/%02d%c.gif", cardset, rank, c);
    images[rank][suit] = new ImageIcon(s.c_str()).getImage();
  }
}
