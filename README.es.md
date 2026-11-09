# bengalaiot-stm32

[Português](README.md) · **Español** · [English](README.en.md)

Versión del **Bastón IoT** para P-NUCLEO-WB55 (STM32WB55). El comportamiento viene de [bengalaiot-core](https://github.com/AssistThings/bengalaiot-core), el algoritmo único de todas las placas; este repositorio contiene solo lo específico de esta placa.

Parte de [AssistThings](https://assistthings.github.io/es/): tecnología asistiva abierta con IA e IoT.

## Estado

| Elemento | Estado |
| --- | --- |
| Algoritmo | Viene del núcleo |
| Conexión con AssistThings Hub | BLE implementado |
| Prueba con hardware real | Pendiente |

## Conexiones

| Componente | Pin |
| --- | --- |
| Sensor bajo (trigger / echo) | D2 / D3 |
| Sensor alto (trigger / echo) | D4 / D5 |
| Motor de vibración | D6 |
| Botón de emergencia (a GND) | D7 |
| Zumbador | D8 |

**Atención:** El HC-SR04 sale a 5 V y esta placa trabaja a 3,3 V: **usa un divisor de tensión en los pines de eco** y un transistor con diodo en el motor.

## Compilar

Clona el núcleo junto a este repositorio:

```bash
git clone https://github.com/AssistThings/bengalaiot-core.git ../bengalaiot-core
```

Grabar en la placa:

```bash
pio run -e board -t upload
```

Comprobar el algoritmo en la placa:

```bash
pio run -e conformance -t upload
pio device monitor
```

El resultado esperado es `failed=0`.

## Lista de pruebas con hardware

- [ ] Sin obstáculo, el motor queda apagado.
- [ ] Con un obstáculo a 1 m frente al sensor bajo, el motor vibra; al acercarlo, vibra más fuerte.
- [ ] Lo mismo ocurre con el sensor alto.
- [ ] Con un sensor sin eco y el otro viendo un obstáculo, vale la lectura del que lo ve.
- [ ] Pulsar el botón genera una alerta y un pitido; mantenerlo no repite la alerta.
- [ ] El dispositivo encuentra `AssistThings Bengala`, recibe la telemetría y aplica `maxDistanceCm=100`.

## Para quienes desarrollan

El punto de entrada es `src/main.cpp`. Antes de cambiar cualquier comportamiento, lee la [arquitectura](https://github.com/AssistThings/bengalaiot-core/blob/main/docs/ARCHITECTURE.es.md): esta placa solo implementa la interfaz de hardware. Las decisiones de cuándo y cuánto vibrar están en el núcleo, para que todas las placas funcionen igual.

## Contribuir

Consulta [cómo contribuir](CONTRIBUTING.es.md) y [quién mantiene esta placa](MAINTAINERS.es.md).

---

Este proyecto es un prototipo de investigación y **no es un dispositivo de seguridad validado**. No sustituye al bastón largo ni al entrenamiento en orientación y movilidad.

## Licencia

[MIT](LICENSE) © AssistThings
