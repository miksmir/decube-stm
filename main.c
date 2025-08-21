#include "main.h"


int main(void)
{
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Initialize all configured peripherals */
  __HAL_RCC_GPIOE_CLK_ENABLE(); // <--- required for GPIOE
  __HAL_RCC_GPIOB_CLK_ENABLE(); // <--- required for GPIOB

  // Technically you only need multiple GPIO_Init structs if the configuration changes for each port.
  // In this case, the struct can be reused.
  GPIO_InitTypeDef GPIO_InitStructE = {0};
  GPIO_InitStructE.Pin = GPIO_PIN_1; // For Yellow LED (User LD2)
  GPIO_InitStructE.Mode = GPIO_MODE_OUTPUT_PP; // For push-pull configuration
  GPIO_InitStructE.Pull = GPIO_NOPULL; // This is not really required (Pin is left floating but PP drives it anyway)
  GPIO_InitStructE.Speed = GPIO_SPEED_FREQ_LOW; // Dictates how fast a rising edge of signal rises
  HAL_GPIO_Init(GPIOE, &GPIO_InitStructE);

  GPIO_InitTypeDef GPIO_InitStructB = {0};
  GPIO_InitStructB.Pin = GPIO_PIN_0 | GPIO_PIN_14; // For Green LED (User LD1) and Red LED (User LD3)
  GPIO_InitStructB.Mode = GPIO_MODE_OUTPUT_PP; // For push-pull configuration
  GPIO_InitStructB.Pull = GPIO_NOPULL; // This is not really required (Pin is left floating but PP drives it anyway)
  GPIO_InitStructB.Speed = GPIO_SPEED_FREQ_LOW; // Dictates how fast a rising edge of signal rises
  HAL_GPIO_Init(GPIOB, &GPIO_InitStructB);

  while (1)
  {
	  // Turn LEDs on incrementally
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET); // (LD3)
	  HAL_Delay(150);
	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET); // (LD2)
	  HAL_Delay(150);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET); // (LD1)
	  HAL_Delay(150);

	  // Turn off all LEDs
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET); // (LD3)
	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET); // (LD2)
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET); // (LD1)
	  HAL_Delay(150);

	  // Turn LEDs on incrementally in reverse
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET); // (LD1)
	  HAL_Delay(150);
	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET); // (LD2)
	  HAL_Delay(150);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET); // (LD3)
	  HAL_Delay(150);

	  // Turn off all LEDs
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET); // (LD3)
	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET); // (LD2)
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET); // (LD1)
	  HAL_Delay(150);
  }
}




