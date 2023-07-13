#include <Wire.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <ctype.h>

int calculate(const char *expression);

int operation(int op1, int op2, char op);

int charToInt(char c);

const byte ROWS = 5;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
    {'.', '.', '.', '*'},
    {'1', '2', '3', '+'},
    {'4', '5', '6', '-'},
    {'7', '8', '9', '/'},
    {'.', '0', '=', '.'}};
byte rowPins[ROWS] = {A0, A1, A2, A3, A4};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char string[30];
int len;

void setup()
{
  lcd.begin(16, 2);
  len = 0;
}

void loop()
{
  char customKey = customKeypad.getKey();
  if (customKey)
  {
    if (customKey == '=')
    {
      string[len] = '\0';
      len = 0;
      int result = calculate(string);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(result);
    }
    else if (customKey == '.')
    {
      lcd.clear();
      lcd.setCursor(0, 0);
    }
    else
    {
      string[len] = customKey;
      len++;
      lcd.print(customKey);
    }
  }
}

int calculate(const char *expression)
{
  int value = 0;
  int second = 0;
  char lastOperand = '+';
  char c;
  for (int i = 0; (expression[i] != '\0'); i++)
  {
    c = expression[i];
    if (isdigit(c))
    {
      second = (second * 10) + charToInt(c);
    }
    else
    {
      value = operation(value, second, lastOperand);
      second = 0;
      lastOperand = c;
    }
  }
  value = operation(value, second, lastOperand);
  return value;
}

int operation(int op1, int op2, char op)
{
  switch (op)
  {
  case '-':
    return op1 - op2;
  case '+':
    return op1 + op2;
  case '/':
    return op1 / op2;
  case '*':
    return op1 * op2;
  default:
    return -1;
  }
}

int charToInt(char c)
{
  return c - '0';
}
