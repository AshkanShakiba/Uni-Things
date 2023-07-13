const int buttonPin = 2;
const int ledPin1 = 3;
const int ledPin2 = 4;
const int ledPin3 = 5;
const int ledPin4 = 6;

int buttonState = 0;
int currNum = 0;

void setup()
{
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

void updateLEDs()
{
  if (currNum > 7)
  {
    digitalWrite(ledPin4, HIGH);
  }
  else
  {
    digitalWrite(ledPin4, LOW);
  }

  if ((currNum > 3 && currNum < 8) || currNum > 11)
  {
    digitalWrite(ledPin3, HIGH);
  }
  else
  {
    digitalWrite(ledPin3, LOW);
  }

  if (currNum % 4 > 1)
  {
    digitalWrite(ledPin2, HIGH);
  }
  else
  {
    digitalWrite(ledPin2, LOW);
  }

  if (currNum % 2 == 1)
  {
    digitalWrite(ledPin1, HIGH);
  }
  else
  {
    digitalWrite(ledPin1, LOW);
  }
}

void IncreaseN()
{
  if (currNum == 15)
  {
    currNum = 0;
  }
  else
  {
    currNum++;
  }
  updateLEDs();
}

void loop()
{
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW)
  {
    IncreaseN();
  }
  delay(200);
}
