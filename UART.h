#ifndef UART_H_
#define UART_H_


void UART_init(void);
void UART_transmit(unsigned char data);
unsigned char UART_receive(void);
void UART_printNumber(uint32_t num);
void UART_printstring(char *str);


#endif /* UART_H_ */
