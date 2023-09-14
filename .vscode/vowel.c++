#include <iostream>
#include <ctime>
#include <iomanip>

int main() {
    // Define the time of arrival and departure as strings
    std::string arrivalTime = "2019-06-01 09:45:56";
    std::string departureTime = "2019-06-02 14:45:56";

    // Parse the strings into time structures
    struct std::tm startTime = {};
    struct std::tm endTime = {};
    std::istringstream arrivalStream(arrivalTime);
    std::istringstream departureStream(departureTime);

    arrivalStream >> std::get_time(&startTime, "%Y-%m-%d %H:%M:%S");
    departureStream >> std::get_time(&endTime, "%Y-%m-%d %H:%M:%S");

    // Calculate the time duration
    std::time_t startTimestamp = std::mktime(&startTime);
    std::time_t endTimestamp = std::mktime(&endTime);
    std::time_t duration = endTimestamp - startTimestamp;

    // Calculate hours, minutes, and seconds
    int hours = duration / 3600;
    int minutes = (duration % 3600) / 60;
    int seconds = duration % 60;

    // Output the result in the desired format
    std::cout << std::setfill('0') << std::setw(2) << hours << ":";
    std::cout << std::setfill('0') << std::setw(2) << minutes << ":";
    std::cout << std::setfill('0') << std::setw(2) << seconds << std::endl;

    return 0;
}
