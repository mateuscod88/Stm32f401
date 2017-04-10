void gpio_for_led_config(){
	__HAL_RCC_GPIOD_CLK_ENABLE();
	GPIO_InitTypeDef gpio_init;
	gpio_init.Pin = GPIO_PIN_12;
	gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_init.Pull = GPIO_PULLUP;
	gpio_init.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOD,&gpio_init);

}
void gpio_for_button_config()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef gpio_init;
	gpio_init.Pin = GPIO_PIN_0;
	gpio_init.Mode = GPIO_MODE_IT_RISING;
	gpio_init.Pull = GPIO_NOPULL;
	gpio_init.Speed = GPIO_SPEED_FREQ_HIGH;
	
	HAL_GPIO_Init(GPIOA,&gpio_init);
	
	NVIC_SetPriority(EXTI0_IRQn,0);
	NVIC_EnableIRQ(EXTI0_IRQn);
	
}

void EXTI0_IRQHandler()
	{
		//HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_SET);
		
	}
