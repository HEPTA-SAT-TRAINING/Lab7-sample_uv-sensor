#include "src/HeptaSat.h"
#include "src/drv/uv_guva_s12sd.h"

HeptaCdh cdh;
HeptaEps eps;
UvGuvaS12sd uv;

// true: MCP3208 channel 5 (USER1, V4.1.1), false: MCU GP28 (ADC2)
constexpr bool kUseMcp3208 = false;
constexpr uint8_t kMcp3208CsPin = 17;
constexpr uint8_t kMcp3208Channel = 5;
constexpr uint8_t kDirectAdcPin = 28;

void setup() {
  cdh.begin();
  eps.init();
  eps.switch_3V3_on();

  if (!uv.begin(kUseMcp3208, kDirectAdcPin, kMcp3208Channel, kMcp3208CsPin)) {
    cdh.println("UV sensor init failed");
    while (true) {
      delay(1000);
    }
  }

  if (kUseMcp3208) {
    cdh.printf("GUVA-S12SD ready (MCP3208 ch%u)\r\n", kMcp3208Channel);
  } else {
    cdh.println("GUVA-S12SD ready (GP28)");
  }
}

void loop() {
  float voltage = uv.get_voltage();
  float illumination = uv.get_illumination_mw_m2();
  float uv_index = uv.get_uv_index();

  cdh.printf("Voltage: %.3f [V]\r\n", voltage);
  cdh.printf("UV illumination: %.1f [mW/m2]\r\n", illumination);
  cdh.printf("UV index: %.2f\r\n", uv_index);

  delay(1000);
}
