#ifndef STRING_UTIL_HPP_INCLUDED
#define STRING_UTIL_HPP_INCLUDED

#include <string>
#include <sstream>

namespace StringUtil
{
//Set the case of a string to lowercase.
inline std::string toLowercase(std::string a_String)
{
std::string anLowerString = a_String;
//from STL's algorithm header
std::transform(anLowerString.begin(), anLowerString.end(), anLowerString.begin(), ::tolower);
return anLowerString;
}
//Set the case of a string to UPPERCASE.
inline std::string toUppercase(std::string a_String)
{
std::string anLowerString = a_String;
//from STL's algorithm header
std::transform(anLowerString.begin(), anLowerString.end(), anLowerString.begin(), ::toupper);
return anLowerString;
}

//Convert a value to a string.
template <class T>
std::string toString(T a_Value)
{
std::stringstream ssReturn;
ssReturn << a_Value;
return ssReturn.str();
}

//Helper functions for common types
inline std::string toString(bool a_bValue) { return toString<bool>(a_bValue); }
inline std::string toString(int a_iValue){return toString<int>(a_iValue);}

//Convert a string to another value;
template <class T>
T toOther(std::string a_sValue)
{
T Return;
std::stringstream sStream(a_sValue);
sStream >> Return;
return Return;
}

//Helper functions for common types
inline int toInt(std::string a_sValue){ return toOther<int>(a_sValue);}
inline bool toBool(std::string a_sValue){ return toOther<bool>(a_sValue);}
}

#endif