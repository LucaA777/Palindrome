#include <iostream>
#include <cstring>

using namespace std;


void stripCharArrayToAlphaNumeric(char s[80]);
void charArrayToLowerCase(char s[80]);

int main() {

  char str[80];

  cin.get(str, 80);
  cin.get();
  
  stripCharArrayToAlphaNumeric(str);
  charArrayToLowerCase(str);
  cout << str << endl;

  
  return (0);
}

void charArrayToLowerCase(char s[80]) {
  for (int i = 0; i < 80; i++) {
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


void stripCharArrayToAlphaNumeric(char s[80]) {
  for (int i = 0; i < 80; i++) {
    /*
      Cuts chars with ASCII values not in the ranges:
      - 48-57
      - 65-90
      - 97-122
     */

    int cASCII = int(s[i]);
    if ( !(cASCII >= 48 && cASCII <= 57) &&
	 !(cASCII >= 65 && cASCII <= 90) &&
	 !(cASCII >= 97 && cASCII <= 122)) {

      memmove(&s[i], &s[i + 1], 80 - i - 1);
    }
  }

  
}
