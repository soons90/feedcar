/*
 * timer_counter.h
 *
 * Created: 2020-04-17 오후 12:52:16
 *  Author: 984
 */ 


#ifndef TIMER_COUNTER_H_
#define TIMER_COUNTER_H_


void timer_counter_overflow_init(void);
void timer1_CTC_outA_speaker_init(void);
void timer0_fast_pwm_suvomotor_init(void);
void timer1_fast_pwm_dcmotor_init(void);
void timer2_fast_pwm_dcmotor_init(void);
#endif /* TIMER_COUNTER_H_ */