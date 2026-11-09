# bengalaiot-stm32

**Português** · [Español](README.es.md) · [English](README.en.md)

Versão da **Bengala IoT** para P-NUCLEO-WB55 (STM32WB55). O comportamento vem do [bengalaiot-core](https://github.com/AssistThings/bengalaiot-core), o algoritmo único de todas as placas; este repositório contém só o que é específico desta placa.

Parte do [AssistThings](https://assistthings.github.io): tecnologia assistiva aberta com IA e IoT.

## Situação

| Item | Estado |
| --- | --- |
| Algoritmo | Vem do núcleo |
| Conexão com o AssistThings Hub | BLE implementado |
| Teste com hardware real | Pendente |

## Ligações

| Componente | Pino |
| --- | --- |
| Sensor baixo (trigger / echo) | D2 / D3 |
| Sensor alto (trigger / echo) | D4 / D5 |
| Motor de vibração | D6 |
| Botão de emergência (ao GND) | D7 |
| Bipador | D8 |

**Atenção:** O HC-SR04 sai em 5 V e esta placa trabalha em 3,3 V: **use divisor de tensão nos pinos de eco** e transistor com diodo no motor.

## Compilar

Clone o núcleo ao lado deste repositório:

```bash
git clone https://github.com/AssistThings/bengalaiot-core.git ../bengalaiot-core
```

Gravar na placa:

```bash
pio run -e board -t upload
```

Conferir o algoritmo na placa:

```bash
pio run -e conformance -t upload
pio device monitor
```

O resultado esperado é `failed=0`.

## Lista de testes com hardware

- [ ] Sem obstáculo, o motor fica desligado.
- [ ] Com um obstáculo a 1 m na frente do sensor baixo, o motor vibra; ao aproximar, vibra mais forte.
- [ ] O mesmo acontece com o sensor alto.
- [ ] Com um sensor sem eco e o outro vendo um obstáculo, vale a leitura do que vê.
- [ ] Apertar o botão gera um alerta e um bipe; mantê-lo apertado não repete o alerta.
- [ ] O aparelho encontra `AssistThings Bengala`, recebe a telemetria e aplica `maxDistanceCm=100`.

## Para quem desenvolve

O ponto de entrada é `src/main.cpp`. Antes de mudar qualquer comportamento, leia a [arquitetura](https://github.com/AssistThings/bengalaiot-core/blob/main/docs/ARCHITECTURE.md): esta placa só implementa a interface de hardware. Decisões de quando e quanto vibrar ficam no núcleo, para todas as placas funcionarem iguais.

## Contribuir

Veja [como contribuir](CONTRIBUTING.md) e [quem mantém esta placa](MAINTAINERS.md).

---

Este projeto é um protótipo de pesquisa e **não é um dispositivo de segurança validado**. Ele não substitui a bengala longa nem o treinamento de orientação e mobilidade.

## Licença

[MIT](LICENSE) © AssistThings
