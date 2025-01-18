String cardset = "cardset-oxymoron";
String suits = "cdhs";

for (int suit = 0; suit &lt;= 3; suit++) {
    char c = suits.charAt(suit);

    for (int rank = 1; rank &lt;= 13; rank++) {
        String s = String.format("%s/%02d%c.gif",
                                 cardset, rank, c);
        images[rank][suit] = new ImageIcon(s).getImage();
    }
}