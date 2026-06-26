# Lab7-sample_uv-sensor

HEPTA-SAT training sample: **Grove UV Sensor** (**GUVA-S12SD**).

## Sensor Specifications

| Item | Value |
|------|-------|
| Module | **Seeed Grove UV Sensor** |
| Sensor element | **GUVA-S12SD** (UV photodiode) |
| Interface | Analog output → **MCP3208 channel 7** |
| Supply | 3.3 V |
| Wavelength sensitivity | approx. 240 to 370 nm (module spec) |
| Conversion | Illuminance [mW/m²] = `307.0 × voltage [V]` |
| UV index | `illuminance / 200` (uses 16-sample averaged voltage) |

## Analog Input Selection

Set `kUseMcp3208` in the sketch:

| `kUseMcp3208` | Connection |
|---------------|------------|
| `true` | **MCP3208 channel 7** (CS = GP17) |
| `false` | **MCU GP28** (ADC2) |

## Wiring (HEPTA-SAT)

| Sensor | HEPTA-SAT |
|--------|-----------|
| Analog output | MCP3208 ch7 **or** GP28 (see above) |
| MCP3208 CS | GP17 (when using MCP3208) |
| VCC | 3.3 V payload |
| GND | GND |

## Build and Upload

1. Open `Lab7-sample_uv-sensor.ino` in the Arduino IDE
2. Board: **Raspberry Pi Pico**
3. Set `kUseMcp3208` to match your wiring
4. Compile and upload
5. Serial monitor at **9600 baud**

## Example Serial Output

```
GUVA-S12SD ready (MCP3208 ch7)
Voltage: 0.206 [V]
UV illumination: 63.2 [mW/m2]
UV index: 0.32
Voltage: 0.413 [V]
UV illumination: 126.8 [mW/m2]
UV index: 0.63
```

## Driver

- `src/drv/uv_guva_s12sd.h` / `.cpp`
- Details: `src/docs/drivers/uv-guva-s12sd.md`
