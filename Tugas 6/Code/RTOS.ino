#include <Arduino_FreeRTOS.h>
#include <semphr.h>

#define LED_PIN 8
#define SENSOR_PIN A0

SemaphoreHandle_t mutex;
volatile int sensorValue = 0;

// deklarasi task
void TaskSensor(void *pvParameters);
void TaskLED(void *pvParameters);
void TaskSerial(void *pvParameters);

void setup() {
  Serial.begin(9600);

  mutex = xSemaphoreCreateMutex();

  // stack kecil biar muat di UNO
  xTaskCreate(TaskSensor, "Sensor", 100, NULL, 2, NULL);
  xTaskCreate(TaskLED,    "LED",    100, NULL, 1, NULL);
  xTaskCreate(TaskSerial, "Serial", 100, NULL, 1, NULL);

  vTaskStartScheduler(); // WAJIB
}

void loop() {
  // kosong karena RTOS
}

// ================= TASK SENSOR =================
void TaskSensor(void *pvParameters) {
  while (1) {
    int val = analogRead(SENSOR_PIN);

    if (xSemaphoreTake(mutex, 5)) {
      sensorValue = val;
      xSemaphoreGive(mutex);
    }

    vTaskDelay(200 / portTICK_PERIOD_MS);
  }
}

// ================= TASK LED =================
void TaskLED(void *pvParameters) {
  pinMode(LED_PIN, OUTPUT);

  while (1) {
    int val = 0;

    if (xSemaphoreTake(mutex, 5)) {
      val = sensorValue;
      xSemaphoreGive(mutex);
    }

    int delayLED = map(val, 0, 1023, 100, 700);

    digitalWrite(LED_PIN, HIGH);
    vTaskDelay(delayLED / portTICK_PERIOD_MS);

    digitalWrite(LED_PIN, LOW);
    vTaskDelay(delayLED / portTICK_PERIOD_MS);
  }
}

// ================= TASK SERIAL =================
void TaskSerial(void *pvParameters) {
  while (1) {
    int val = 0;

    if (xSemaphoreTake(mutex, 5)) {
      val = sensorValue;
      xSemaphoreGive(mutex);
    }

    Serial.print("Sensor: ");
    Serial.print(val);

    Serial.print(" | Delay LED: ");
    Serial.println(map(val, 0, 1023, 100, 700));

    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}