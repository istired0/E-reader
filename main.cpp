#include "WString.h"
#include "esp32-hal.h"
#include <Arduino.h>
#include <Seeed_GFX.h>
#include <cstddef>

// put function declarations here:
Seeed_GFX display(Seeed_Product::Seeed-ePaper_4INCH26);
struct Task{
  const char *text;
  bool done;
};
Task tasks[] = {
  {"Drink Water", false},
  {"Study", true}
};

const size_t Tasksn = sizeof(tasks) / sizeof(tasks[0]);
size_t selectedtask = 0;
bool needsupdate = true;

void list(){
  display.fillScreen(TFT_WHITE);
  display.setTextColor(TFT_BLACK);
  display.setTextSize(4);
  display.setCursor(30,40);
  display.drawString("To-do-list");
  display.setTextSize(3);

  int y = 90;
  for(size_t i = 0; i<Tasksn; i++){
    String row; 
    row += (i == selectedtask) ? "> " : "  ";

    row += tasks[i].done ? "[X]" : "[ ]";

    row += tasks[i].text;

    display.drawString(row, 35, y)

    y += 30;
    
  }
}
void setup() {
  // put your setup code here, to run once:
  // Serial.begin(115200);
  // if (!display.begin()){
  //   Serial.println(display.lastResult().message);
  //   return;
  // }

  // display.fillScreen(TFT_WHITE);
  // display.fillRect(0,0, display.width(), 86, TFT_BLACK);
  // display.setTextColor(TFT_WHITE);
  // display.setTextSize(3);
  // display.drawString("Hello World", 48, 28);


  // display.update();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
}

// put function definitions here: