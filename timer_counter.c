/*
 * timer_counter.c
 *
 * Created: 2020-04-17 오후 12:19:32
 *  Author: 984
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

unsigned int count = 0;
char state = 0;

ISR(TIMER0_COMPA_vect){
	
}
void timer_counter_main(void){
	while(1){
		
	}
}

void timer_counter_overflow_init(void){
	TCCR0B |= 1<<CS02 | 1<<CS00; // 분주비 1024
	TIMSK0 |= 1<< TOIE0; //오버플로우 인터럽트 허용
	DDRB |= 1 << PORTB5;
	PORTB = 0x00;
}

void timer_counter_cmp_init(void){
	TCCR0B |= 1<< CS01  | 1<<WGM12; // 분주비 1024
	OCR0A = 0; // 비교일치 기준 값
	//TIMSK0 |= 1<< OCIE0A; //비교일치 인터럽트 허용
	TCCR0A |= 1<<COM1A0;
	DDRD |= 1<< PORTD6;
	PORTD = 0x00;
}

void timer1_CTC_outA_speaker_init(void){
	DDRB |= 1 << PORTB1;
	TCCR1A |= 1 << COM1A0;
	TCCR1B |= 1 << WGM12| 1 << CS11;
	OCR1A = 0;
	return;
}

void timer0_fast_pwm_suvomotor_init(void){
	DDRD |= 1 << PORTD6;
	TCCR0A |= 1 << WGM00 | 1 << WGM01 | 1 << COM0A1;
	TCCR0B |= 1 << CS02 | 1 << CS00;
	OCR0A = 37;
}

void timer1_fast_pwm_dcmotor_init(void){
	DDRB |= 1 << PORTB2 | 1 << PORTB4;
	TCCR1A |= 1 << WGM10  | 1 << COM1B1; // 256분주 비반전 8bit fast pwm top
	TCCR1B |= 1 << WGM12  | 1 << CS12;
}

void timer2_fast_pwm_dcmotor_init(void){
	DDRB |= 1 << PORTB3 | 1 << PORTB5;
	TCCR2A |= 1 << WGM21 | 1 << WGM20 | 1<< COM2A1; // 256분주 비반전 fast pwm top max
	TCCR2B |= 1 << CS22 | 1 << CS21;
}