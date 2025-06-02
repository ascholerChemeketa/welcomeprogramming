
    string f1Name = f1.getName();
    CHECK(f1Name == "Ronnie");

    // f1 is an object, so we can call getFriend directly
    // the pointer that is returned is a Person*, so we must then use -> to call getName
    string f2Name = f1.getFriend()->getName();
    CHECK(f2Name == "Dakota");

    string f3Name = f1.getFriend()->getFriend()->getName();
    CHECK(f3Name == "Mary");

    string f4Name = f1.getFriend()->getFriend()->getFriend()->getName();
    CHECK(f4Name == "Ronnie");
}