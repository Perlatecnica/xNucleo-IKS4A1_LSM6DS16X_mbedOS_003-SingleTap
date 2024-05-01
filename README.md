# xNucleo-IKS4A1_LSM6DSV16X_mbedOS_004-SingleTap

This application shows how to detect the single tap event using the LSM6DSV16X accelerometer.

---
### Description:

This code demonstrates the use of interrupts with the LSM6DSV16X sensor to detect single tap events. It configures an interrupt to trigger when a single tap is detected by the sensor and blinks an LED as an indication. Upon detecting a single tap event, it prints a message over the serial connection.

### How it works:

- **Initialization**: 
  - It includes necessary libraries for communication (`mbed.h`) and for interfacing with the LSM6DSV16X sensor (`plt_iks4a1.h`).
  - It initializes objects for serial communication (`Serial`), an LED for visual indication, and an interrupt pin (`InterruptIn`).
  - It sets up an interrupt callback function (`INT1Event_cb`) to handle interrupts.

- **Sensor Configuration**: 
  - It initializes the LSM6DSV16X sensor and enables the accelerometer.
  - It configures the sensor to detect single tap events on the X-axis and assigns the interrupt pin for interrupt triggering.

- **Main Loop**:
  - It enters an infinite loop where it continuously checks if a tap event has occurred.
  - When a tap event is detected, it toggles the LED to indicate detection and prints a message over the serial connection.

- **Interrupt Event Handler**:
  - When the interrupt occurs, it sets a flag to indicate an event.

---

This description provides an overview of the code's functionality, including initialization, interrupt setup, sensor configuration, and tap event detection.
