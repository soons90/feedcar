#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "timer_counter.h"
#include "UART.h"
#include "timer_counter.h"
#define AUTOMODE 1
#define MANUALMODE 0
void process_feed(void);
void process_Bleft(void);
void process_Bright(void);
void process_Fright(void);
void process_Fleft(void);
void process_right(void);
void process_left(void);
void process_foward(void);
void process_back(void);
void process_auto_1(void);
void process_auto_2(void);
void process_auto_3(void);
void process_stop(void);
int main(void)
{
    UART_init();
	timer0_fast_pwm_suvomotor_init();
	timer1_fast_pwm_dcmotor_init();
	timer2_fast_pwm_dcmotor_init();
	DDRC |= 1 << PORTC0; // LED 레지스터 설정
	char mode = MANUALMODE;
	char data;
	while (1) // 디폴트 모드인 수동모드로 시작해서 모드에 따라서 프로세스 진행
    {
		data = UART_receive();
		if(data == 'W'){
			mode = AUTOMODE; //1
			PORTC = 1 << PORTC0;
		}
		else if(data == 'w'){
			mode = MANUALMODE;
			PORTC = 0; //0
		}
		
		if(mode == MANUALMODE){
			switch(data){
				case 'F':
				{	
					process_foward();
					break;
				}
				case 'B':
				{
					process_back();
					break;
				}
				case 'R':
				{
					process_right();
					break;
				}
				case 'L':
				{
					process_left();
					break;
				}
				case 'G': // f+l
				{
					process_Fleft();
					break;
				}
				case 'I': //
				{
					process_Fright();
					break;
				}
				case 'H':
				{
					process_Bleft();
					break;
				}
				case 'J':
				{
					process_Bright();
					break;
				}
				case 'U':
				{
					process_feed();
					break;
				}
				default:
				{
					process_stop();
					break;
				}
			}
		}
		if(mode == AUTOMODE){
			switch(data){
				case 'F':{
					process_auto_1();
					break;
				}
				case 'R':{
					process_auto_2();
					break;
				}
				case 'L':{
					process_auto_3();
					break;
				}
				case 'B':{
					process_stop();
					break;
				}
				case 'U':
				{
					process_feed();
					break;
				}
			}
		}
		
	}
}

void process_auto_1(void){ //자동 앞
	PORTB = 0b00001100;
	OCR1B = 160;
	OCR2A = 160;
}

void process_auto_2(void){ //왼쪽으로 돈다
	PORTB = 0b00001100;
	OCR1B = 160;
	OCR2A = 0;
}

void process_auto_3(void){ // 오른쪽으로 돈다
	PORTB = 0b00001100;
	OCR1B = 0;
	OCR2A = 160;
}

void process_foward(void){
	PORTB = 0b00001100;
	OCR1B = 160;
	OCR2A = 160;
}

void process_back(void){
	PORTB = 0b00111100;
	OCR1B = 160;
	OCR2A = 160;
}

void process_left(void){
	PORTB = 0b00001100;
	OCR1B = 0;
	OCR2A = 160;
}

void process_right(void){
	PORTB = 0b00001100;
	OCR1B = 160;
	OCR2A = 0;
}

void process_Fright(void){
	PORTB = 0b00001100;
	OCR1B = 160;
	OCR2A = 120;
}
void process_Fleft(void){
	PORTB = 0b00001100;
	OCR1B = 120;
	OCR2A = 160;
}
void process_Bright(void){
	PORTB = 0b00111100;
	OCR1B = 160;
	OCR2A = 120;
}
void process_Bleft(void){
	PORTB = 0b00111100;
	OCR1B = 120;
	OCR2A = 160;
}

void process_feed(void){ //간식 주기
	OCR0A = 18;
	_delay_ms(500);
	OCR0A = 37;
	_delay_ms(500);
}
void process_stop(void){ // 멈춤
	OCR1B = 0;
	OCR2A = 0;
}
