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
void gpio_for_uart1TX_config()
{
	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitTypeDef gpio_init;
	gpio_init.Pin |= GPIO_PIN_6 ;
	gpio_init.Mode = GPIO_MODE_AF_PP ;
	gpio_init.Pull = GPIO_PULLUP;
	gpio_init.Speed = GPIO_SPEED_FREQ_HIGH;
	
	HAL_GPIO_Init(GPIOB,&gpio_init);
}
void gpio_for_uart1RX_config()
{
	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitTypeDef gpio_init;
	gpio_init.Pin |= GPIO_PIN_7 ;
	gpio_init.Mode = GPIO_MODE_INPUT ;
	gpio_init.Pull = GPIO_NOPULL;
	gpio_init.Speed = GPIO_SPEED_FREQ_HIGH;
	
	HAL_GPIO_Init(GPIOB,&gpio_init);
}
void nvic_for_uart1()
{
	NVIC_SetPriority(USART1_IRQn,0);
	NVIC_EnableIRQ(USART1_IRQn);
}
void sendUart()
{
	HAL_UART_Transmit_IT();
}
void  HAL_UART_TxCpltCallback()
{
	tu sie wykonuje po wyslaniu
}
void HAL_UART_IRQHandler() 
{
	
}
void USART1_IRQHandler()
{
	
}
void EXTI0_IRQHandler()
	{
		//HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_SET);
		
	}

void usart_config()
{
	
	
	UART_InitTypeDef uart_init;
	uart_init.BaudRate = 9600;
	uart_init.WordLength = UART_WORDLENGTH_8B;
	uart_init.StopBits = UART_STOPBITS_1;
	uart_init.Parity = UART_PARITY_NONE;
	uart_init.Mode = UART_MODE_TX_RX;
	uart_init.OverSampling = UART_OVERSAMPLING_16; 
	
	UART_HandleTypeDef huart;
	huart.Instance = &uart_init;
	
}