/*
 * Exercise 4-6. Add commands for handling variables.
 * (It’s easy to provide twenty-six variables with single-letter names.)
 * Add a variable for the most recently printed value.”
 *
 * From: "The C Programming Language, Second Edition"
 * by Brian W. Kernighan and Dennis M. Ritchie
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

#define VARNUM 26
#define SETVAR ']'
#define GETVAR '['

char buf[BUFSIZE];
int bufp = 0;

int sp = 0;
double val[MAXVAL];

int var_index = 0;
double var_buff[VARNUM];

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void peek();
void duplicate();
void swap();
void clear();

int main() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch(type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
         printf("error: zero divisor=n");
        break;
      case '%':
        op2 = pop();
        if (op2 != 0.0)
          push(((int)pop()) % (int)op2);
        else
         printf("error: zero divisor=n");
        break;
      case 'p':
        peek();
        break;
      case 'd':
        duplicate();
        break;
      case 's':
        swap();
        break;
      case 'c':
        clear();
        break;
      case 'i':
        push(sin(pop()));
        break;
      case 'e':
        push(exp(pop()));
        break;
      case 'w':
        op2 = pop();
        push(pow(pop(), op2));
        break;
      case GETVAR:
        if(var_index > 0){
          push(var_buff[--var_index]);
        }
        break;
      case SETVAR:
        var_buff[var_index++] = pop();
        printf("Var %c: %0.f\n", 'a' + var_index-1, var_buff[var_index - 1]);
        break;
      case '\n':
        if(sp > 0) {
          printf("\t%.8g\n", pop());
        }
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }

  return 0;
}

void peek() {
  printf("\ntop: %.1f\n", val[sp]);
}

void duplicate() {
  double top = val[sp-1];
  val[sp++] = top;
}

void swap() {
  double tmp = val[sp-1];
  val[sp-1] = val[sp-2];
  val[sp-2] = tmp;
}

void clear() {
  sp = 0;
  val[sp] = 0;
}

void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
   printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

int getop(char s[]) {
  int i, c, op;
  while((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  if (!isdigit(c) && c != '.') {
    if(c != '-') {
      return c;
    } else {
      op = c;
    }

  }

  if(c == '-') {
    if(isdigit(c = getch())) {
      ungetch(c);
    } else {
      ungetch(c);
      return op;
    }
  }

  i = 0;


  if (isdigit(c)) {
    while (isdigit(s[++i] = c = getch())) {
      ;
    }
  }

  if (c == '.') {
    while (isdigit(s[++i] = c = getch())) {
      ;
    }
  }

  s[i] = '\0';

  if (c != EOF) {
    ungetch(c);
  }
  return NUMBER;
}


int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}
