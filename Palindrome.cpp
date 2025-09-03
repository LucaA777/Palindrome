/*
This program takes an input and checks if its a palindrome. Only alphanumeric
characters are used in the process, and all others are removed.

Author: Luca Ardanaz
Last Updated: 9/3/2025
 */

/*
THE THREE RULES OF C++

1. NO GLOBAL VARIABLES

2. NO STRINGS

3. USE include <iostream> INSTEAD OF stdio
*/

#include <iostream>
#include <cstring>

using namespace std;

const int inLim = 80; //Defines the maximum input size


//function initializations 
int stripCharArrayToAlphaNumeric(char s[inLim]);
void charArrayToLowerCase(char s[inLim]);

int main() {

  //define char array
  char str[inLim];

  //get text from the user
  cout << "Please enter a word or phrase (max 80 characters):" << endl;
  cin.get(str, inLim);
  cin.get();

  //prepare the cstring for reversal
  int strLen = stripCharArrayToAlphaNumeric(str); //returns new str length 
  charArrayToLowerCase(str);

  //reverse the cstring
  char strRev[inLim]; //sets up reversed cstring
  for (int i = 0; i < strLen; i++) {
    strRev[i] = str[strLen - i - 1];
  }
  strRev[strLen] = '\0'; //adds cstring terminator
  

  //checks if the string is a palindrome
  if (strcmp(str, strRev) == 0) {
    cout << "Palindrome." << endl;
  }
  else {
    cout << "Not a palindrome." << endl;
  }
  
  return (0);
}

//alters the passed char array to convert any upper case letters to lower case
void charArrayToLowerCase(char s[inLim]) {
  for (int i = 0; i < inLim; i++) {
    /*
      Looks at all ASCII values, any between 65 and 90 are upper case.
      Adding 32 to them will convert them to lower case
     */

    int cASCII = int(s[i]);
    if (cASCII >= 65 && cASCII <= 90) {
      s[i] = char(cASCII + 32);
    }
  }
}


//removes all non-alphanumeric characters, returns the new length
int stripCharArrayToAlphaNumeric(char s[inLim]) {
  for (int i = 0; i < inLim; i++) {
    /*
      Cuts chars with ASCII values not in the ranges:
      - 48-57
      - 65-90
      - 97-122
     */

    int cASCII = int(s[i]);

    //if its the null character, end the function
    if (cASCII == 0) {
      return i; //returns the length of the new cstring
    }
    
    //otherwise, check for whether its something that needs to be moved.
    else if ( !(cASCII >= 48 && cASCII <= 57) &&
	 !(cASCII >= 65 && cASCII <= 90) &&
	 !(cASCII >= 97 && cASCII <= 122)) {

      memmove(&s[i], &s[i + 1], inLim - i - 1);
      i--;
    }
  }

  return -1; //THIS IS A PROBLEM BECAUSE IT MEANS THERES NO NULL CHARACER
}
