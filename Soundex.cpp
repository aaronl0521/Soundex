#include "Soundex.h"

std::string Soundex::encode(const std::string &word) const
{
    auto encoded = head(word);

    encoded += encodedDigits(word);
    
    return zeroPad(encoded);
}

std::string Soundex::head(const std::string &word) const
{
    return word.substr(0, 1);
}

std::string Soundex::encodedDigits(const std::string &word) const
{
    if (word.length() > 1)
        return "1";  
    return "";
}

std::string Soundex::zeroPad(const std::string &word) const 
{
    const auto kSoundexLength = 4;
    auto zeroNeeded = kSoundexLength - word.length();
    return word + std::string(zeroNeeded, '0');
}