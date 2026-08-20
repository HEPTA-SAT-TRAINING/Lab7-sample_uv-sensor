# Lab7-sample_uv-sensor

HEPTA-SAT training sample: **Grove UV Sensor** (**GUVA-S12SD**).

## Sensor Specifications

| Item | Value |
|------|-------|
| Module | **Seeed Grove UV Sensor** |
| Sensor element | **GUVA-S12SD** (UV photodiode) |
| Interface | Analog output → **MCP3208 USER1 / USER2 / USER3** (V4.1.1) |
| Supply | 3.3 V |
| Wavelength sensitivity | approx. 240 to 370 nm (module spec) |
| Conversion | Illuminance [mW/m²] = `307.0 × voltage [V]` |
| UV index | `illuminance / 200` (uses 16-sample averaged voltage) |

## Analog Input Selection

Set `kUserChannel` in the sketch to match the board USER pin:

| `kUserChannel` | Board pin | MCP3208 |
|----------------|-----------|---------|
| `1` | **USER1** | CH5 |
| `2` | **USER2** | CH6 |
| `3` | **USER3** | CH7 |

## Wiring (HEPTA-SAT V4.1.1)

| Sensor | HEPTA-SAT |
|--------|-----------|
| Analog output | USER1 / USER2 / USER3 (see `kUserChannel`) |
| VCC | 3.3 V payload (`eps.switch_3V3_on()`) |
| GND | GND |

## Build and Upload

1. Open `Lab7-sample_uv-sensor.ino` in the Arduino IDE
2. Board: **Raspberry Pi Pico**
3. Check out the `src/` submodule (`git submodule update --init`)
4. Set `kUserChannel` to match your wiring (`1`, `2`, or `3`)
5. Compile and upload
6. Serial monitor at **9600 baud**

## Example Serial Output

```
GUVA-S12SD ready (USER1 / MCP3208 ch5)
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
