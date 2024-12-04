string num_str;
while (true) {
    cout << "Enter a number: ";
    if (getline(cin, num_str)
        && all_of(num_str.begin(), num_str.end(), ::isdigit)) {
        double number = stod(num_str);
        break; // Exit the loop if input is valid
    } else {
        cerr << "Invalid input. Please enter a valid number.\n";
    }
}
double number = stod(num_str);