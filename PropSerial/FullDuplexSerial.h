//
// automatically generated by spin2cpp v3.0.0 on Sat Apr 16 20:30:46 2016
// spin2cpp --ccode FullDuplexSerial.spin 
//

#ifndef FullDuplexSerial_Class_Defined__
#define FullDuplexSerial_Class_Defined__

#include <stdint.h>

// unix end of line
#define EOL (10)

typedef struct FullDuplexSerial {
// cog flag/id
  volatile int32_t	cog;
// 9 contiguous longs
  volatile int32_t	rx_head;
  volatile int32_t	rx_tail;
  volatile int32_t	tx_head;
  volatile int32_t	tx_tail;
  volatile int32_t	rx_pin;
  volatile int32_t	tx_pin;
  volatile int32_t	rxtx_mode;
  volatile int32_t	bit_ticks;
  volatile int32_t	buffer_ptr;
// transmit and receive buffers
  volatile uint8_t	rx_buffer[16];
  volatile uint8_t	tx_buffer[16];
  volatile uint8_t	txlock;
  volatile uint8_t	strlock;
} FullDuplexSerial;

  int32_t FullDuplexSerial_start(FullDuplexSerial *self, int32_t rxpin, int32_t txpin, int32_t mode, int32_t baudrate);
  void FullDuplexSerial_stop(FullDuplexSerial *self);
  void FullDuplexSerial_txflush(FullDuplexSerial *self);
  void FullDuplexSerial_rxflush(FullDuplexSerial *self);
  int32_t FullDuplexSerial_rx(FullDuplexSerial *self);
  void FullDuplexSerial_tx(FullDuplexSerial *self, int32_t txbyte);
  void FullDuplexSerial_str(FullDuplexSerial *self, int32_t stringptr);
#endif
