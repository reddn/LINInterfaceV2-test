#ifndef STRUCTH
#define STRUCTH

#include <Arduino.h>



struct incomingLKASMessage {
	uint8_t totalCounter = 0;
	uint8_t data[4];
	bool sent = false;
	uint8_t counterBit = 0;
	uint8_t bigSteer = 0;
	uint8_t littleSteer = 0;
	uint8_t lkasOn = 0;
	uint8_t checksum = 0;
};


typedef struct CAN_message_t {
  volatile int id = 0;          // can identifier
  uint16_t timestamp = 0;   // FlexCAN time when message arrived
  uint8_t idhit = 0; // filter that id came from
  struct {
    bool extended = 0; // identifier is extended (29-bit)
    bool remote = 0;  // remote transmission request packet type
    bool overrun = 0; // message overrun
    bool reserved = 0;
  } flags;
  uint8_t len = 8;      // length of data
  uint8_t buf[8] = { 0 };       // data
  int8_t mb = 0;       // used to identify mailbox reception
  uint8_t bus = 0;      // used to identify where the message came from when events() is used.
  bool seq = 0;         // sequential frames
} CAN_message_t;


typedef struct
{
  uint32_t id;        /* 29 bit identifier                               */
  uint8_t  buf[8] = {0};   /* Data field                                      */
  uint8_t  len;       /* Length of data field in bytes                   */
  uint8_t  ch;        /* Object channel(Not use)                         */
  uint8_t  format = 0;    /* 0 - STANDARD, 1- EXTENDED IDENTIFIER            */
  uint8_t  type = 0;      /* 0 - DATA FRAME, 1 - REMOTE FRAME                */
} CAN_msg_t;


#endif