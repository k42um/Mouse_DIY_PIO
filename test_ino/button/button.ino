#define LEFT_BUTTON_PIN D5
#define RIGHT_BUTTON_PIN D4

void setup(){
    Serial.begin(115200);

    pinMode(LEFT_BUTTON_PIN, INPUT_PULLUP);
    pinMode(RIGHT_BUTTON_PIN, INPUT_PULLUP);
}

void loop(){
    Serial.print("L: ");
    Serial.print(digitalRead(LEFT_BUTTON_PIN));
    Serial.print(" , R: ");
    Serial.println(digitalRead(RIGHT_BUTTON_PIN));

    delay(100);
}