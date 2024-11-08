//Startup.c
//Saif Essam
#include <stdint.h>

void Default_Handeler()
{
	void Reset_Handeler();
}
void Reset_Handeler();
void NMI_Handeler() __attribute__((weak, alias("Default_Handeler")));;
void H_fault_Handeler() __attribute__((weak, alias("Default_Handeler")));;
void MM_fault_Handeler() __attribute__((weak, alias("Default_Handeler")));;
void Bus_Handeler() __attribute__((weak, alias("Default_Handeler")));;
void Usage_Fault_Handeler() __attribute__((weak, alias("Default_Handeler")));;

extern unsigned int _stack_top;

uint32_t vectors[] __attribute__((section(".vector"))) = 
{ 
 (uint32_t) &_stack_top,
 (uint32_t) &Reset_Handeler,
 (uint32_t) &NMI_Handeler,
 (uint32_t) &H_fault_Handeler,
 
 (uint32_t) &Bus_Handeler,
 (uint32_t) &Usage_Fault_Handeler,	

};

extern unsigned int _E_TEXT;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_BSS;
extern unsigned int _E_BSS;



void Reset_Handeler()
{
	int i=0;
	//Copy data section from falsh to ram
	unsigned int DATA_SIZE	= (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char* P_src = (unsigned char*)&_E_DATA ;
	unsigned char* P_det = (unsigned char*)&_S_DATA ;
	for(i; i<DATA_SIZE; i++)
	{
		*((unsigned char*)P_det++) = *((unsigned char*)P_src++);
	}
	//init .bss section in sram = 0
	unsigned int bss_size	= (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	P_det = (unsigned char*)&_S_BSS ;
	for(i; i<bss_size; i++)
	{
		*((unsigned char*)P_det++) = (unsigned char*)0 ;
	}

	// jump to main
	main();

}





