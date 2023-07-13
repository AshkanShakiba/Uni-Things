float temp;
int reading;
const int led = 13;

void setup()
{
    pinMode(led, OUTPUT);
    Serial.begin(9600);
    analogReference(INTERNAL);
}

void loop()
{
    reading = analogRead(A0);
    temp = (reading * 110.0) / 1023;
    Serial.println(temp);
    delay(500);
    if (temp > 29)
    {
        digitalWrite(led, HIGH);
    }
}