#include <string>
#include <cmath>
#include <iostream>

using namespace std;

int myAtoi(string str) {
  int res = 0;
  int size = str.length();
  if (size==0)
    return 0;
  char arr[size];
  int i = 0;
  int j = -1;
  // handle front ' '
  while (i < size && str[i] == ' ')
    i++;
  // handle sign
  bool flag = true;  // positive
  if (str[i] == '-' || str[i] == '+') {
    if (str[i] == '-')
      flag = false;
    i++;
  }

  // 0 begin ' ' begin after sign return 0
  if (str[i] == 0 || str[i] == ' ')
    return 0;
  // ok,here we can handle the number and letter 
  while (i < size) {
    if (!(str[i] >= '0' && str[i] <= '9')) { // until first not number position,then break
      break;
    } else {
      j++;
      arr[j] = str[i]; 
    }
    i++; // move forward
  }

  // ok,add sum to res and check overflow and underflow 
  int max = ((unsigned int) - 1) >> 1;
  if (j == -1) return 0;
  for (i = 0; i <= j; i++) {
    res += (arr[i] - '0') * pow(10, j - i);          
    if (res < 0) {  
      if (flag == true) return max;
      else return (max+1);  // -2147483648
    }
  }
  if (flag == true) return res;
  else return -res;
}

int main(int argc, char *argv[])
{
  string s = "  +0 125";
  string s1 = " - ab";
  string s2 = "1111111111111111111";
  string s3 = "-1111111111111111111";
  string s4 = "18446744073709551617";
  cout << myAtoi(s) << "\n";
  cout << myAtoi(s1) << "\n";
  cout << myAtoi(s2) << "\n";
  cout << myAtoi(s3) << "\n";
  cout << myAtoi(s4) << "\n";
  return 0;
}
