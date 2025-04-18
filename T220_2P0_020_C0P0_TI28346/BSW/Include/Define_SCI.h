/*
 * Define_SCI.h
 *
 * C/C++ source code generated on : Thu Jan 11 10:09:04 2024
 * Created by: System Research Team
 * Code generated on : Sat Mar 15 00:16:24 2025
 *
 */

#ifndef DEFINE_SCI_H_
#define DEFINE_SCI_H_

#ifdef __cplusplus
extern "C" {
#endif

// ADD or IDLE Mode
#define MODE_IDLE			0x0
#define MODE_ADDR			0x1

// Parity
#define PARITY_ODD			0x0
#define PARITY_EVEN			0x1

// Parity Enable
#define PARITYEN_DISABLE	0x0
#define PARITYEN_ENABLE		0x1

// Character Length
#define SCICHAR_1BIT		0x0
#define SCICHAR_2BIT		0x1
#define SCICHAR_3BIT		0x2
#define SCICHAR_4BIT		0x3
#define SCICHAR_5BIT		0x4
#define SCICHAR_6BIT		0x5
#define SCICHAR_7BIT		0x6
#define SCICHAR_8BIT		0x7

// Stop Bits
#define STOPBITS_1BIT		0x0
#define STOPBITS_2BIT		0x1

// Transmitter Enable
#define TX_DISABLE			0x0
#define TX_ENABLE			0x1

// Receiver Enable
#define RX_DISABLE			0x0
#define RX_ENABLE			0x1

// SCI Reset
#define SCI_RESET			0x0
#define SCI_RESUME			0x1

// FIFO Enable
#define FIFO_DISABLE		0x0
#define FIFO_ENABLE			0x1

// FIFO Interrupt Enable
#define FIFO_INT_DISABLE	0x0
#define FIFO_INT_ENABLE		0x1

// FIFO Interrupt Clear
#define FIFO_INT_CLEAR		0x1

// FIFO Interrupt Level
#define FIFO_INT_0BYTE		0x00
#define FIFO_INT_1BYTE		0x01
#define FIFO_INT_2BYTE		0x02
#define FIFO_INT_3BYTE		0x03
#define FIFO_INT_4BYTE		0x04
#define FIFO_INT_5BYTE		0x05
#define FIFO_INT_6BYTE		0x06
#define FIFO_INT_7BYTE		0x07
#define FIFO_INT_8BYTE		0x08
#define FIFO_INT_9BYTE		0x09
#define FIFO_INT_10BYTE		0x0A
#define FIFO_INT_11BYTE		0x0B
#define FIFO_INT_12BYTE		0x0C
#define FIFO_INT_13BYTE		0x0D
#define FIFO_INT_14BYTE		0x0E
#define FIFO_INT_15BYTE		0x0F
#define FIFO_INT_16BYTE		0x10

// SCI Interrupt
#define SCI_INT_DISABLE		0x0
#define SCI_INT_ENABLE		0x1

// SCI Sleep Mode
#define SLEEP_DISABLE		0x0
#define SLEEP_ENABLE		0x1

// Union Data for RS-232
struct UtoB{
	Uint16				BYTE0:8;
	Uint16				BYTE1:8;
};

struct FtoB{
	Uint16				BYTE0:8;
	Uint16				BYTE1:8;
	Uint16				BYTE2:8;
	Uint16				BYTE3:8;
};

union DD_UINT16{
	Uint16 				UINT16;
	struct UtoB			BYTE;
};

union DD_FLOAT{
	float				FLOAT;
	struct FtoB			BYTE;
};

typedef struct _RS232_{
	union DD_UINT16		MODE;
	union DD_FLOAT		DATA;
} RS232;

#ifdef __cplusplus
}
#endif

#endif /* DEFINE_SCI_H_ */
