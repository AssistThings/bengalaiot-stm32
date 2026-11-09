// Bengala IoT — STM32WB55. O comportamento está em bengalaiot-core.
#include <Arduino.h>
#include <STM32duinoBLE.h>
#include <bengala/bengala.h>
#include <bengala/ports/arduino_hal.h>
#include <bengala/ports/arduinoble_link.h>

using namespace bengala;

// Mude aqui se ligar em outros pinos. Ver README.
static const ArduinoPins kPins = {D2, D3, D4, D5, D6, D7, D8};

static ArduinoBleLink link("stm32wb55");

class BoardHal : public ArduinoHal {
 public:
  using ArduinoHal::ArduinoHal;

  void sendAlert(const char *message) override {
    ArduinoHal::sendAlert(message);
    link.alert(message);
  }

  void publishTelemetry(const char *line) override {
    ArduinoHal::publishTelemetry(line);
    link.telemetry(line);
  }
};

static BoardHal hal(kPins);
static Cane cane(hal);

void setup() {
  Serial.begin(115200);
  hal.beginPins();
#ifdef BENGALA_CONFORMANCE
  delay(2000);
  const ConformanceReport report = runConformance();
  Serial.print("conformance total=");
  Serial.print(report.total);
  Serial.print(" failed=");
  Serial.println(report.failed);
#endif
  if (!link.begin()) Serial.println("BLE indisponivel");
  if (!Cane::abiMatches()) Serial.println("bengalaiot-core: versao incompativel");
  cane.begin();
}

void loop() {
  link.poll(cane);
  cane.tick();
}
