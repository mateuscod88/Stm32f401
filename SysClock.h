#ifdef SYS_CLOCK

//RCC 0x40023800 ahb1
//CRC 0x40023000 ahb1
//SYSCFG 0x40013800 apb2
void PLL_CONFIG()
{
	RCC_CR &= RCC_CR_PLL_OFF;
	RCC_CR & = RCC_CR_HSE_OFF;
	RCC_PLLCFGR |= RCC_PLLCFGR_M | RCC_PLLCFGR_N | RCC_PLLCFGR_P;
	RCC_PLLCFGR |= RCC_PLLCFGR_SRC_HSE;
	RCC_CFGR |= RCC_CFGR_SW_PLL | RCC_CFGR_APB1_SPEED_DIV4 | RCC_CFGR_APB2_SPEED_DIV1 | RCC_CFGR_AHB_SPEED_DIV1 | RCC_CFGR_SW_PLL;
	
}
#define RCC_CR (*((unsigned int *) 0x40023800))
#define RCC_CR_PLL_ON 1U << 24
#define RCC_CR_PLL_OFF (~(1U << 24))
#define RCC_CR_HSE_ON 1U << 16
#define RCC_CR_HSE_OFF (~(1U << 16))
//przed wlaczeniem PLL ustaw SRC
//najpierw wlacz PLL

#define RCC_PLLCFGR (*((unsigned int *) 0x40023804))
#define RCC_PLLCFGR_M 8U << 0
#define RCC_PLLCFGR_N 336U << 6
#define RCC_PLLCFGR_P 1U << 16
#define RCC_PLLCFGR_SRC_HSE 1U << 22 // hse musi byc wylaczone

#define RCC_CFGR (*((unsigned int *) 0x40023808))
#define RCC_CFGR_SW_PLL 2U << 0
#define RCC_CFGR_APB1_SPEED_DIV4 5U << 10
#define RCC_CFGR_APB2_SPEED_DIV1 0U << 13
#define RCC_CFGR_AHB_SPEED_DIV1 0U << 4

#define RCC_AHB1ENR (*((unsigned int *) 0x40023830))

#endif