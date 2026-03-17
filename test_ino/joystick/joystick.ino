#define JOY_BUTTON_PIN D3
#define X_AXIS_PIN A0
#define Y_AXIS_PIN A1

void setup(){
    pinMode(JOY_BUTTON_PIN, INPUT_PULLUP);

    Serial.begin(115200);
}

void loop(){
    if(!digitalRead(JOY_BUTTON_PIN)) Serial.println("JOY_BUTTON PUSHED");

    Serial.print("X: ");
    Serial.print(analogRead(X_AXIS_PIN));
    Serial.print(", Y: ");
    Serial.println(analogRead(Y_AXIS_PIN));
}