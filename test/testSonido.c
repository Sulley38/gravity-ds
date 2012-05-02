#include <nds.h>
#include <stdio.h>


int ESTADO;

int main() {
	int partitura[4]={7000,10500,10500,10500};
	int notas[13] =
	{
		4186 ,//Do	0
		4434 ,//Do#	1
		4698 ,//Re	2
		4978 ,//Re#	3
		5274 ,//Mi	4
		5587 ,//Fa	5
		5919 ,//Fa#	6
		6271 ,//Sol	7
		6644 ,//Sol	8
		7040 ,//La	9
		7458 ,//La#	10
		7902 ,//Si	11
		1000,	 //vacio 12
	};
	int freq=1;
	int n=1;
	soundEnable();
	int channel = soundPlayPSG(DutyCycle_50, partitura[0], 127,64);




	while(TRUE)	{
		if (freq==4 )			soundPause(channel);
		if (n%5==0 && freq<4){
			soundResume(channel);
			soundSetFreq(channel,partitura[freq]);
			freq ++;
		}
		if (n==100){
			freq=0;
			n=0;
		}

		swiWaitForVBlank();
		n++;
	}

	return 0;
}
