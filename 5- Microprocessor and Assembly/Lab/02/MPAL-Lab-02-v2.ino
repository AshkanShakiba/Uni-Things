#include <Keypad.h>
#include <LiquidCrystal.h>

// 1. LCD Pins
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// 2. Keypad Pins
const byte Rows = 4;
const byte Cols = 4;
char keys[Rows][Cols] =
    {
        {'1', '2', '3', '+'},
        {'4', '5', '6', '-'},
        {'7', '8', '9', '*'},
        {'C', '0', '=', '/'}};
byte rowPins[Rows] = {A0, A1, A2, A3};
byte colPins[Cols] = {5, 4, 3, 2};
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, Rows, Cols);

boolean presentValue = false;
boolean next = false;
boolean final = false;
String num1, num2;
int answer;
char op;

void setup()
{
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("welcome");
    lcd.setCursor(0, 1);
    lcd.print("   Calculator");
    delay(3000);
    lcd.clear();
}

void loop()
{

    char key = myKeypad.getKey();

    if (key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0'))
    {
        if (presentValue != true)
        {
            num1 = num1 + key;
            int numLength = num1.length();
            lcd.setCursor(15 - numLength, 0); //to adjust one whitespace for operator
            lcd.print(num1);
        }
        else
        {
            num2 = num2 + key;
            int numLength = num2.length();
            lcd.setCursor(15 - numLength, 1);
            lcd.print(num2);
            final = true;
        }
    }

    else if (presentValue == false && key != NO_KEY && (key == '/' || key == '*' || key == '-' || key == '+'))
    {
        if (presentValue == false)
        {
            presentValue = true;
            op = key;
            lcd.setCursor(15, 0);
            lcd.print(op);
        }
    }

    else if (final == true && key != NO_KEY && key == '=')
    {
        if (op == '+')
        {
            answer = num1.toInt() + num2.toInt();
        }
        else if (op == '-')
        {
            answer = num1.toInt() - num2.toInt();
        }
        else if (op == '*')
        {
            answer = num1.toInt() * num2.toInt();
        }
        else if (op == '/')
        {
            answer = num1.toInt() / num2.toInt();
        }
        lcd.clear();
        lcd.setCursor(15, 0);
        lcd.autoscroll();
        lcd.print(answer);
        lcd.noAutoscroll();
    }
    else if (key != NO_KEY && key == 'C')
    {
        lcd.clear();
        presentValue = false;
        final = false;
        num1 = "";
        num2 = "";
        answer = 0;
        op = ' ';
    }
}