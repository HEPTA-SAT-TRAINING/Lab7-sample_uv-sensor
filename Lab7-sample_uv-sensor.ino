#include "src/HeptaSat.h"

HeptaCdh cdh;
HeptaEps eps;
HeptaUvGuvaS12sd uv;

void setup() {
  cdh.begin();
  eps.init();
  eps.switch_3V3_on();

  if (!uv.begin(USER1)) {
    cdh.println("UV sensor init failed");
    while (true) {
      delay(1000);
    }
  }

  cdh.println("GUVA-S12SD ready");
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
