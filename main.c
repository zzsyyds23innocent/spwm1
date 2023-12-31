#include <msp430.h>

unsigned int spwm_i,spwm_j;
unsigned int Lab_base[]={99,105,111,117,123,129,135,141,146,152,157,162,166,171,175,179,182,185,188,191,193,194,196,197,197,198,197,197,196,194,193,191,188,185,182,179,175,171,166,162,157,152,146,141,135,129,123,117,111,105,99,92,86,80,74,68,62,56,51,45,40,35,31,26,22,18,15,12,9,6,4,3,1,0,0,0,0,0,1,3,4,6,9,12,15,18,22,26,31,35,40,45,51,56,62,68,74,80,86,92
};
float Lab1[]={99,105,111,117,123,129,135,141,146,152,157,162,166,171,175,179,182,185,188,191,193,194,196,197,197,198,197,197,196,194,193,191,188,185,182,179,175,171,166,162,157,152,146,141,135,129,123,117,111,105,99,92,86,80,74,68,62,56,51,45,40,35,31,26,22,18,15,12,9,6,4,3,1,0,0,0,0,0,1,3,4,6,9,12,15,18,22,26,31,35,40,45,51,56,62,68,74,80,86,92
};//这个float数组我是用来调节调制深度的，改变这里的值就可以改变输出的幅度了
void SPWM_1Way_Init();
void SPWM_1Way_Set_Freq(unsigned int freq);
int main(void)
{

	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	//MCLK SMCLK 1MHz ACLK 12KHz
	BCSCTL2 = SELM_0 | DIVM_0 | DIVS_0;
	if (CALBC1_1MHZ != 0xFF) {
	DCOCTL = 0x00;
	BCSCTL1 = CALBC1_1MHZ; /* Set DCO to 1MHz */
	DCOCTL = CALDCO_1MHZ;
	}
	BCSCTL1 |= XT2OFF | DIVA_0;
	BCSCTL3 = XT2S_0 | LFXT1S_2 | XCAP_1;

	P1DIR |= BIT6; // P1.2 output
	P1SEL |= BIT6; // P1.2 TA0.1 options
	CCR0 = 200; // PWM Period 10K  10000
	CCTL1 = OUTMOD_7; // CCR1 reset/set
	TACTL = TASSEL_2 + MC_1; // SMCLK, up mode
	int i=0;
	for(;;){
	CCR1=Lab1[spwm_i];
	spwm_i++;
	if(spwm_i==100)spwm_i=0;
	for(i = 0;i < 9; i++); //采样延时
	}

	return 0;
}



