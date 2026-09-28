# ESP32 Button-Controlled LED

## Problem Statement

Read a push-button's state and toggle an external LED, with basic software debouncing.

## Objective

To understand:

- Digital input using a push-button
- Digital output using an LED
- Internal pull-up resistor
- Software debouncing
- LED state toggling

## Components

- ESP32 DevKitC V4
- Push-button
- LED
- 220Ω resistor

## GPIO Configuration

| Component | ESP32 GPIO |
|-----------|------------|
| Push-button | GPIO 4 |
| External LED | GPIO 2 |

## Working

The push-button is configured using the ESP32's internal pull-up resistor.

When the button is not pressed, the input reads HIGH.

When the button is pressed, the input reads LOW.

Each valid button press toggles the LED:

- LED OFF → LED ON
- LED ON → LED OFF

A 50 ms software debounce is used to prevent mechanical button bouncing from being interpreted as multiple presses.

## Debouncing

The program checks whether the button state has remained stable for at least 50 ms before accepting the state change.

## Wokwi Simulation

The circuit is simulated in Wokwi before testing on physical hardware.

## Result

The external LED toggles its state with each button press while basic software debouncing prevents unintended multiple toggles.