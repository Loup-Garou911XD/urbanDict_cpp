#ifndef URBAN_DICTIONARY_H
#define URBAN_DICTIONARY_H 
/* include guard
This ensures that subsequent inclusion of the same header file in the same translation 
unit will not cause the contents of the header file to be processed again.*/

#include <string>

// Function prototype for performing the API request
std::string UrbanDictionaryRequest(const std::string &term);

#endif

