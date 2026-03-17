#include <Arduino.h>
#include <Mouse.h>

#define LEFT_BUTTON_PIN D4
#define RIGHT_BUTTON_PIN D5

#define JOY_BUTTON_PIN D3
#define X_AXIS_PIN A0
#define Y_AXIS_PIN A1

#define JOY_SENSITIVITY 15
#define JOY_CENTER_THRESHOLD 20

void setup(){
    pinMode(LEFT_BUTTON_PIN, INPUT_PULLUP);
    pinMode(RIGHT_BUTTON_PIN, INPUT_PULLUP);
    pinMode(JOY_BUTTON_PIN, INPUT_PULLUP);

    Serial.begin(115200);

    Mouse.begin();
}

void loop(){
    //FIXME: 一回ボタンを押しただけでも、複数クリック判定になってしまう。

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

    // ジョイスティックのボタン（左ボタン扱い）
    if(!digitalRead(JOY_BUTTON_PIN) && !Mouse.isPressed(MOUSE_LEFT)){ 
        Mouse.press(MOUSE_LEFT);
    }

    if(digitalRead(JOY_BUTTON_PIN) && Mouse.isPressed(MOUSE_LEFT)){
        Mouse.release(MOUSE_LEFT);
    }

    int x = analogRead(X_AXIS_PIN);
    int y = analogRead(Y_AXIS_PIN);

    int8_t xMove = map(x, 0, 1023, 127, -128);
    int8_t yMove = map(y, 0, 1023, 127, -128);

    if(abs(xMove) < JOY_CENTER_THRESHOLD) xMove = 0;
    if(abs(yMove) < JOY_CENTER_THRESHOLD) yMove = 0;

    Mouse.move(xMove / JOY_SENSITIVITY, yMove / JOY_SENSITIVITY, 0);
}

// 参考: https://speeddemon.jp/mouse-h/