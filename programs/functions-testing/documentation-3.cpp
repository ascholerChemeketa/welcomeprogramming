/**
 * @brief Get the average high temperature (in Fahrenheit) for
 *        the specified day of the year
 * @param day Day of the year. Jan 1st = 1, Feb 1st = 32...
 * @return degrees F
 * 
 * This function will connect to weather.com to retrieve the
 * average high temperature for the specified day. If a network
 * error occurs, the function will return -1.
 */
double getAverageHighTemperature(int day);