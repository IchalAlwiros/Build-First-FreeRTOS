#include <Arduino_FreeRTOS.h>


void Task_Print1(void *param);
void Task_Print2(void *param);


TaskHandle_t Task_Handle1;
TaskHandle_t Task_Handle2;


void setup() {
Serial.begin(9600);

//Prioritas tertinggi, itu akan dijalankan terlebih dalu
xTaskCreate(Task_Print1,"Task1",100,NULL,1,&Task_Handle1);
xTaskCreate(Task_Print2,"Task2",100,NULL,2,&Task_Handle2);
}

void loop() {
//Dead Loop
}

void Task_Print1(void *param)
{
  (void)param;

  while(1)
  {
    Serial.println("Belajari Print 1");
    vTaskDelay(1000/portTICK_PERIOD_MS);
    }
  }

  void Task_Print2(void *param)
{
  (void)param;

  while(1)
  {
    Serial.println("Belajari Print 2");
    vTaskDelay(1000/portTICK_PERIOD_MS);
    }
  }
