    ...
    double thetaRadians = thetaDegrees * numbers::pi / 180;

    double x = 2;
    double y = 4;

    double x2 = x * cos(thetaRadians) - y * sin(thetaRadians);
    cout << "x2: " << x2 << endl;
    double y2 = x * sin(thetaRadians) + y * cos(thetaRadians);
    cout << "y2: " << y2 << endl;