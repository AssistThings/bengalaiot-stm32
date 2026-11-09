# bengalaiot-stm32

[Português](README.md) · [Español](README.es.md) · **English**

**Smart Cane IoT** version for P-NUCLEO-WB55 (STM32WB55). The behavior comes from [bengalaiot-core](https://github.com/AssistThings/bengalaiot-core), the single algorithm for all boards; this repository holds only what is specific to this board.

Part of [AssistThings](https://assistthings.github.io/en/): open assistive technology with AI and IoT.

## Status

| Item | State |
| --- | --- |
| Algorithm | Comes from the core |
| Connection to AssistThings Hub | BLE implemented |
| Test with real hardware | Pending |

## Wiring

| Component | Pin |
| --- | --- |
| Low sensor (trigger / echo) | D2 / D3 |
| High sensor (trigger / echo) | D4 / D5 |
| Vibration motor | D6 |
| Emergency button (to GND) | D7 |
| Buzzer | D8 |

**Warning:** The HC-SR04 outputs 5 V and this board runs at 3.3 V: **use a voltage divider on the echo pins** and a transistor with a diode for the motor.

## Build

Clone the core next to this repository:

```bash
git clone https://github.com/AssistThings/bengalaiot-core.git ../bengalaiot-core
```

Flash the board:

```bash
pio run -e board -t upload
```

Check the algorithm on the board:

```bash
pio run -e conformance -t upload
pio device monitor
```

The expected result is `failed=0`.

## Hardware test list

- [ ] With no obstacle, the motor stays off.
- [ ] With an obstacle 1 m in front of the low sensor, the motor vibrates; moving closer, it vibrates harder.
- [ ] The same happens with the high sensor.
- [ ] With one sensor on no echo and the other seeing an obstacle, the reading that sees it applies.
- [ ] Pressing the button creates an alert and a beep; holding it does not repeat the alert.
- [ ] The device finds `AssistThings Bengala`, receives telemetry and applies `maxDistanceCm=100`.

## For developers

The entry point is `src/main.cpp`. Before changing any behavior, read the [architecture](https://github.com/AssistThings/bengalaiot-core/blob/main/docs/ARCHITECTURE.en.md): this board only implements the hardware interface. Decisions on when and how much to vibrate live in the core, so all boards work the same.

## Contributing

See [contributing](CONTRIBUTING.en.md) and [who maintains this board](MAINTAINERS.en.md).

---

This project is a research prototype and **is not a validated safety device**. It does not replace the long cane or orientation and mobility training.

## License

[MIT](LICENSE) © AssistThings
