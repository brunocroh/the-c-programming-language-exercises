#include <ctype.h>
#include <stdio.h>

int htoi(char *s);
int poww(int a, int b);

int main() {
  printf("value: %d", htoi("0xaa"));
}

int htoi(char *s) {
  int len, res, i, d;

  i = len = res = 0;

  while (s[i] != '\0') {
    i++;
  }
  len = i-1;
  
  i = 0;
  d = 0;

  while(s[i] != '\0') {
    if(s[i] == '0' && s[i+1] == 'x') {
      i += 2;
      len -= 2;
    }

    if (isdigit(s[i])) {
      d = s[i] - '0';
    } else {
      d = s[i]-'W';
    }


    if(len > 0) {
      res += d * poww(16, len);
    } else {
      res += d;
    }

    len--;
    i++;
  }

  return res;
}

int poww(int a, int b) {
  int r = a;

  while (--b > 0) {
    r = r * a;
  }

  return r ? r : 1;
}
