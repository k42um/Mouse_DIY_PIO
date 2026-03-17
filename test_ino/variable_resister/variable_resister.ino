#define VARIABLE_RESISTER_PIN A2

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    Serial.println(analogRead(VARIABLE_RESISTER_PIN));
}