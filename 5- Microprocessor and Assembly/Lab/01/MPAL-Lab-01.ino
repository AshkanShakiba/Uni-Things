int button;
int number;
int counter;

void setup()
{
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  counter = 0;
  button = digitalRead(2);
  while (counter < 16)
  {
    if (button == LOW)
    {
      number = counter;
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
      digitalWrite(4, LOW);
      digitalWrite(3, LOW);
      if (number > 7)
      {
        digitalWrite(6, HIGH);
        number -= 8;
      }
      if (number > 3)
      {
        digitalWrite(5, HIGH);
        number -= 4;
      }
      if (number > 1)
      {
        digitalWrite(4, HIGH);
        number -= 2;
      }
      if (number > 0)
      {
        digitalWrite(3, HIGH);
        number -= 1;
      }
      counter += 1;
      delay(500);
    }
  }
}
