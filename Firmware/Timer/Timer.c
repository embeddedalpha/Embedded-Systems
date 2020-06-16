#include "Timer.h"

void Timer_Delay_Init(TIM_TypeDef *timer)
{
if(timer == TIM1)
{
RCC ->APB2ENR |= RCC_APB2ENR_TIM1EN;
}
else if(timer == TIM2)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
}
else if(timer == TIM3)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM3EN;
}
else if(timer == TIM3)
{
RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
}
}


//************************************************** uSECOND DELAY **************************************************



void Timer_Delay_us(TIM_TypeDef *timer,float usSeconds)
{

	timer->SR = 0;
	timer->PSC = 1;
	if(timer == TIM1)
	{
	timer -> ARR = (usSeconds*TIMER_CLOCK_ADVANCED)/2; 
	}
	else
	{
	timer -> ARR = (usSeconds*TIMER_CLOCK_GENERAL)/2; 
	}
	timer->CR1 |= TIM_CR1_URS;
	timer->CR1 |= TIM_CR1_CEN;
	while(!(timer ->SR & TIM_SR_UIF)){} //WAIT TIIL UIF BIT IS SET
}
//

//************************************************** mSECOND DELAY **************************************************

void Timer_Delay_ms(TIM_TypeDef *timer,float msSeconds)
{

	timer->SR = 0;
	if(timer == TIM1){
	timer->PSC = 72;
	timer -> ARR = (msSeconds*TIMER_CLOCK_ADVANCED)/2; 
	}
	else{
	timer->PSC = 36;
	timer -> ARR = (msSeconds*TIMER_CLOCK_GENERAL)/2; 
	}
	timer->CR1 |= TIM_CR1_URS;
	timer->CR1 |= TIM_CR1_CEN;
	while(!(timer->SR & TIM_SR_UIF)){} //WAIT TIIL UIF BIT IS SET
}

//************************************************** SECONDS DELAY **************************************************

void Timer_Delay_s(TIM_TypeDef *timer,float Seconds){

	timer->SR = 0;
	timer->PSC = 65535;
	timer -> ARR = (Seconds*TIMER_CLOCK_ADVANCED)/2; 
	timer->CR1 |= TIM_CR1_URS;
	timer->CR1 |= TIM_CR1_CEN;
	while(!(timer->SR & TIM_SR_UIF)){} //WAIT TIIL UIF BIT IS SET
}

//************************************************** COUNTER MODE **************************************************

void Up_Counter(TIM_TypeDef *timer, uint16_t count)
{
timer -> SR = 0; //clear SR reg
timer -> ARR = count; // value to which the counter counts
if(timer == TIM1)
{
timer -> PSC = 71;    // Prescalar
}
else
{
timer -> PSC = 35; 
}
timer -> CR1 &= ~TIM_CR1_DIR; //Upcounting mode  
timer -> CR1 |= TIM_CR1_URS; //only upcounting generates event
timer -> CR1 |= TIM_CR1_CEN; // Enable Timer
while(!(timer ->SR & TIM_SR_UIF)){}
}
//

void Down_Counter(TIM_TypeDef *timer, uint16_t count)
{
timer -> SR = 0; //clear SR reg
timer -> ARR = count; // value to which the counter counts
if(timer == TIM1)
{
timer -> PSC = 71;    // Prescalar
}
else
{
timer -> PSC = 35; 
}
timer -> CR1 |= TIM_CR1_DIR; //Downcounting mode  
timer -> CR1 |= TIM_CR1_URS; //only upcounting generates event
timer -> CR1 |= TIM_CR1_CEN; // Enable Timer
while(!(timer ->SR & TIM_SR_UIF)){}
}
//

void CenterAligned_Counter(TIM_TypeDef *timer, uint16_t count)
{
timer -> SR = 0; //clear SR reg
timer -> ARR = count; // value to which the counter counts
if(timer == TIM1)
{
timer -> PSC = 71;    // Prescalar
}
else
{
timer -> PSC = 35; 
}
timer -> CR1 |= (TIM_CR1_CMS_1 | TIM_CR1_CMS_0); //CMS[1:0] = [1:1]
timer -> CR1 |= TIM_CR1_URS; //only upcounting generates event
timer -> CR1 |= TIM_CR1_CEN; // Enable Timer
while(!(timer ->SR & TIM_SR_UIF)){}
}
//

//************************************************** INPUT CAPTURE MODE **************************************************


uint16_t Timer_Input_Capture_Channel_1(TIM_TypeDef *TIM)
{
	if(TIM == TIM1)
	{
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	}
	if(TIM == TIM2)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}
	if(TIM == TIM3)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}
	if(TIM == TIM4)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}

	TIM->CCMR1 |= TIM_CCMR1_CC1S_0; //INPUT : CHANNEL 1
	TIM -> CCMR1 |= (TIM_CCMR1_IC1F_0 | TIM_CCMR1_IC1F_1);
	TIM -> CCER &= ~TIM_CCER_CC1P;
	TIM -> CCMR1 &= ~TIM_CCMR1_IC1PSC;
	TIM -> CCER |= TIM_CCER_CC1E;
	TIM -> CR1 |= TIM_CR1_CEN;
	TIM->  SR = ~TIM_SR_CC2IF;
	
	while(!(TIM -> SR & TIM_SR_CC1IF)){}
	return (uint16_t)TIM->CCR1;
}


uint16_t Timer_Input_Capture_Channel_2(TIM_TypeDef *TIM)
{
	if(TIM == TIM1)
	{
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

	}
	if(TIM == TIM2)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}
	if(TIM == TIM3)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}
	if(TIM == TIM4)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}

	TIM->CCMR1 |= TIM_CCMR1_CC1S_0; //INPUT : CHANNEL 1
	TIM -> CCMR1 |= (TIM_CCMR1_IC2F_0 | TIM_CCMR1_IC2F_1);
	TIM -> CCER &= ~TIM_CCER_CC2P;
	TIM -> CCMR1 &= ~TIM_CCMR1_IC2PSC;
	TIM -> CCER |= TIM_CCER_CC2E;
	TIM -> CR1 |= TIM_CR1_CEN;
	TIM ->SR = ~TIM_SR_CC2IF;
	while(!(TIM -> SR & TIM_SR_CC2IF)){}
	return (uint16_t)TIM->CCR2;
}


uint16_t Timer_Input_Capture_Channel_3(TIM_TypeDef *TIM)
{
	if(TIM == TIM1)
	{
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	}
	if(TIM == TIM2)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}
	if(TIM == TIM3)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}
	if(TIM == TIM4)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}

	TIM->CCMR2 |= TIM_CCMR2_CC3S_0; //INPUT : CHANNEL 1
	TIM -> CCMR2 |= (TIM_CCMR2_IC3F_0 | TIM_CCMR2_IC3F_1);
	TIM -> CCER &= ~TIM_CCER_CC3P;
	TIM -> CCMR2 &= ~TIM_CCMR2_IC3PSC;
	TIM -> CCER |= TIM_CCER_CC3E;
	TIM -> CR1 |= TIM_CR1_CEN;
	while(!(TIM -> SR & TIM_SR_CC3IF)){}
	return (uint16_t)TIM->CCR3;
}


uint16_t Timer_Input_Capture_Channel_4(TIM_TypeDef *TIM)
{
	if(TIM == TIM1)
	{
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	}
	if(TIM == TIM2)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}
	if(TIM == TIM3)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}
	if(TIM == TIM4)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}

	TIM->CCMR2 |= TIM_CCMR2_CC4S_0; //INPUT : CHANNEL 1
	TIM -> CCMR2 |= (TIM_CCMR2_IC4F_0 | TIM_CCMR2_IC4F_1);
	TIM -> CCER &= ~TIM_CCER_CC4P;
	TIM -> CCMR2 &= ~TIM_CCMR2_IC4PSC;
	TIM -> CCER |= TIM_CCER_CC4E;
	TIM -> CR1 |= TIM_CR1_CEN;
	while((TIM -> SR & TIM_SR_CC4IF)){}
	return (uint16_t)TIM->CCR4;
}

//************************************************** PWM INPUT MODE **************************************************


uint32_t Timer_Input_PWM_Capture_Channel_1(TIM_TypeDef *TIM)
{
	if(TIM == TIM1)
	{
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	}
	if(TIM == TIM2)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}
	if(TIM == TIM3)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}
	if(TIM == TIM4)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}
	TIM -> CCMR1 |= TIM_CCMR1_CC1S_0; //IC1 mapped to T1
	TIM -> CCMR1 |= TIM_CCMR1_CC2S_1; //IC2 mapped to T1

	TIM -> CCMR1 |= (TIM_CCMR1_IC1F_0 | TIM_CCMR1_IC1F_1);
	TIM -> CCMR1 |= (TIM_CCMR1_IC2F_0 | TIM_CCMR1_IC2F_1);

	TIM -> CCER &= ~TIM_CCER_CC1P; //non inverted
	TIM -> CCER |= TIM_CCER_CC2P; //inverted

	TIM -> SMCR |= TIM_SMCR_TS_2 | TIM_SMCR_TS_0; //trigger select

	TIM -> SMCR |= TIM_SMCR_SMS_2;

	TIM -> CCMR1 &= ~TIM_CCMR1_IC1PSC;
	TIM -> CCMR1 &= ~TIM_CCMR1_IC2PSC;

	TIM -> CCER |= TIM_CCER_CC1E;
	TIM -> CCER |= TIM_CCER_CC2E;

	TIM -> CR1 |= TIM_CR1_CEN;

	return (TIM->CCR1 << 16 | TIM->CCR2);
}

uint32_t Timer_Input_PWM_Capture_Channel_2(TIM_TypeDef *TIM)
{
	if(TIM == TIM1)
	{
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	}
	if(TIM == TIM2)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}
	if(TIM == TIM3)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}
	if(TIM == TIM4)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}
	TIM -> CCMR2 |= TIM_CCMR2_CC3S_0; //IC1 mapped to T1
	TIM -> CCMR2 |= TIM_CCMR2_CC4S_1; //IC2 mapped to T1

	TIM -> CCMR2 |= (TIM_CCMR2_IC3F_0 | TIM_CCMR2_IC3F_1);
	TIM -> CCMR2 |= (TIM_CCMR2_IC4F_0 | TIM_CCMR2_IC4F_1);

	TIM -> CCER &= ~TIM_CCER_CC3P; //non inverted
	TIM -> CCER |= TIM_CCER_CC4P; //inverted

	TIM -> SMCR |= TIM_SMCR_TS_2 | TIM_SMCR_TS_0; //trigger select

	TIM -> SMCR |= TIM_SMCR_SMS_2;

	TIM -> CCMR2 &= ~TIM_CCMR2_IC3PSC;
	TIM -> CCMR2 &= ~TIM_CCMR2_IC4PSC;

	TIM -> CCER |= TIM_CCER_CC3E;
	TIM -> CCER |= TIM_CCER_CC4E;

	TIM -> CR1 |= TIM_CR1_CEN;

	return (TIM->CCR3 << 16 | TIM->CCR4);
}
