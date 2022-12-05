#include "tappity.h"
#include <iostream>
/**
 * Class for tappity
**/

using namespace std;

tappity::tappity(){
    tappity::strInput = "";
    tappity::strReference = "";
}

//////Constructor sets the reference phrase
tappity::tappity(std::string reference){tappity::strReference = reference;}

//Provide the input to be compared to the reference. Before this
//function is called, the input should be considered an empty string
void tappity::entry(std::string input){tappity::strInput = input;}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{   std::string input = tappity::strInput;
    std::string reference = tappity::strReference;
    int inLength = input.length();
    int refLength = reference.length();

    if(inLength >= refLength){
        return abs(inLength-refLength);
    }
    else
        return abs(refLength-inLength);
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy() {
    std::string input = tappity::strInput;
    std::string reference = tappity::strReference;
    int sizeDiff = length_difference();
    double nullVal = 100.0;
    double temp = 0.0;
    auto count = 0.0;
    //Base Case Empty is a Match
    if (input == "" && reference == "") return nullVal;

    // set the index of smaller and larger arrays
    if (input.length() >= reference.length()) {
        temp = input.length();
        for (auto i = 0; i < input.length() - sizeDiff; i++) {
            if (input[i] == reference[i])count += 1;// if match found +1

        }
    }
    else
        {
        temp = reference.length();
        // line index of larger possible array as start and ending point
        for (auto i = 0; i < reference.length() - sizeDiff; i++) {
            if (input[i] == reference[i])count += 1;  // if match found +1

            }
        }
    // Remove the decimal places to return in integer form
    int rounded = (count/temp) *100;
    return rounded;

}
