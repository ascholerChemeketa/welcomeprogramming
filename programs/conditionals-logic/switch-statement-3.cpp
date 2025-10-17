// assume dayOfWeek is an int variable with a value from 0 to 6
// with 0 = Sunday, 1 = Monday, ..., 6 = Saturday
switch (dayOfWeek) {
case 1:
case 2:
case 3:
case 4:
case 5:
    cout << "Weekday!";
    break;
case 0:
case 6:
    cout << "Weekend!";
    break;
}