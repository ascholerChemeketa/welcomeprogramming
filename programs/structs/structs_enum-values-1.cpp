int getValue(Coin c) {
    switch (c) {
        case Coin::PENNY: return 1;
        case Coin::NICKEL: return 5;
        case Coin::DIME: return 10;
        case Coin::QUARTER: return 25;
    }
}