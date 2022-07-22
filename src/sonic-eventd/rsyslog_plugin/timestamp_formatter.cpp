#include <iostream>
#include "timestamp_formatter.h"
#include "logger.h"

using namespace std;

/***
 *
 * Formats given string into string needed by YANG model
 *
 * @param timestamp parsed from syslog message
 * @return formatted timestamp that conforms to YANG model
 *
 */

const unordered_map<string, string> g_monthDict {
    { "Jan", "01" },
    { "Feb", "02" },
    { "Mar", "03" },
    { "Apr", "04" },
    { "May", "05" },
    { "Jun", "06" },
    { "Jul", "07" },
    { "Aug", "08" },
    { "Sep", "09" },
    { "Oct", "10" },
    { "Nov", "11" },
    { "Dec", "12" }
};

string TimestampFormatter::getYear(string timestamp) {
    if(!m_storedTimestamp.empty()) {
        if(m_storedTimestamp.compare(timestamp) <= 0) {
            m_storedTimestamp = timestamp;
            return m_storedYear;
        }
    }
    // no last timestamp or year change
    time_t currentTime = time(nullptr);
    tm* const localTime = localtime(&currentTime);
    stringstream ss;
    auto currentYear = 1900 + localTime->tm_year;
    ss << currentYear; // get current year
    string year = ss.str();
    m_storedTimestamp = timestamp;
    m_storedYear = year;
    return year;
}

string TimestampFormatter::changeTimestampFormat(string message) {
    smatch dateComponents;
    string formattedTimestamp; // need to change format of Mmm dd hh:mm:ss.SSSSSS to YYYY-mm-ddThh:mm:ss.SSSSSSZ
    if(!regex_search(message, dateComponents, m_expression) || dateComponents.size() != 4) { //whole,month,day,time
        SWSS_LOG_ERROR("Timestamp unable to be broken down into components.\n");
        return ""; // empty string is error
    }
    string month;
    auto it = g_monthDict.find(dateComponents[1].str());
    if(it != g_monthDict.end()) {
        month = it->second;
    } else {
        SWSS_LOG_ERROR("Timestamp month was given in wrong format.\n");
        return "";
    }
    string day = dateComponents[2].str();
    if(day.size() == 1) { // convert 1 -> 01
       day.insert(day.begin(), '0');
    }
    string time = dateComponents[3].str();
    string currentTimestamp = month + day + time;
    string year = getYear(currentTimestamp);

    formattedTimestamp = year + "-" + month + "-" + day + "T" + time + "Z";
    return formattedTimestamp;
}

TimestampFormatter::TimestampFormatter(string timestampFormatRegex) {
    regex expr(timestampFormatRegex);
    m_expression = expr;
}
