#include "src/HeptaSat.h"
#include "src/drv/uv_guva_s12sd.h"

HeptaCdh cdh;
HeptaEps eps;
UvGuvaS12sd uv;

// V4.1.1 payload ADC: USER1 / USER2 / USER3 -> MCP3208 CH5 / CH6 / CH7
constexpr uint8_t kUserChannel = 1;  // set to 1, 2, or 3
constexpr uint8_t kMcp3208CsPin = 17;

constexpr uint8_t mcp_channel_from_user(uint8_t user) {
  return static_cast<uint8_t>(4 + user);
}

void setup() {
  cdh.begin();
  eps.init();
  eps.switch_3V3_on();

  if (kUserChannel < 1 || kUserChannel > 3) {
    cdh.println("kUserChannel must be 1, 2, or 3");
    while (true) {
      delay(1000);
    }
  }

  const uint8_t mcp_channel = mcp_channel_from_user(kUserChannel);
  if (!uv.begin(kMcp3208CsPin, mcp_channel)) {
    cdh.println("UV sensor init failed");
    while (true) {
      delay(1000);
    }
  }

  cdh.printf("GUVA-S12SD ready (USER%u / MCP3208 ch%u)\r\n", kUserChannel,
             mcp_channel);
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
