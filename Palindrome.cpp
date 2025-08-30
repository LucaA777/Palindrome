#include <iostream>
#include <cstring>

using namespace std;

int main() {

  char str[80];

  cin.get(str, 80);
  cin.get();

  int ASCII = int(str[0]);
  cout << str << ":" << ASCII << endl;

  
  return (0);
}

void stripCharArrayToAlphaNumeric(char[] str) {
  for (int i = 0; i < 80; i++) {
    /*
      Cuts chars with ASCII values not in the ranges:
      - 48-57
      - 65-90
      - 97-122
     */

    int cASCII = int(str[i]);
    if ( !(cASCII >= 48 && cASCII <= 57) &&
	 !(cASCII >= 65 && cASCII <= 90) &&
	 !(cASCII >= 97 && cASCII <= 122)) {

      
    }
  }
}



