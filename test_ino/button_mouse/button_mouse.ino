#include <Mouse.h>

#define LEFT_BUTTON_PIN D4
#define RIGHT_BUTTON_PIN D5

void setup(){
    Serial.begin(115200);

    pinMode(LEFT_BUTTON_PIN, INPUT_PULLUP);
    pinMode(RIGHT_BUTTON_PIN, INPUT_PULLUP);

    Mouse.begin();
}

void loop(){
    // 左ボタン
    if(!digitalRead(LEFT_BUTTON_PIN) && !Mouse.isPressed(MOUSE_LEFT)){ 
        Mouse.press(MOUSE_LEFT);
    }

    if(digitalRead(LEFT_BUTTON_PIN) && Mouse.isPressed(MOUSE_LEFT)){
        Mouse.release(MOUSE_LEFT);
    }

    // 右ボタン
    if(!digitalRead(RIGHT_BUTTON_PIN) && !Mouse.isPressed(MOUSE_RIGHT)){ 
        Mouse.press(MOUSE_RIGHT);
    }

    if(digitalRead(RIGHT_BUTTON_PIN) && Mouse.isPressed(MOUSE_RIGHT)){
        Mouse.release(MOUSE_RIGHT);
    }
}