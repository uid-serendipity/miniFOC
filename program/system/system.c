#include "gd32f1x0.h"
#include "system.h"

volatile static uint32_t delay;

/*!
    \brief      initialize systick timer to implementation delay function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void systick_config(void) {
    if (SysTick_Config(SystemCoreClock / 1000U))
        while (1);
    NVIC_SetPriority(SysTick_IRQn, 0x00U);
}

/*!
    \brief      millisecond delay function, any time time.
    \param[in]    count: time to delay (in milliseconds)
    \param[out]   none
    \retval       none
*/
void delayms(uint32_t count) {
    delay = count;
    while (0U != delay);
}

/*!
    \brief      delay counter decrement function, called by systick handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void delay_decrement(void) {
    if (0U != delay)
        delay--;
}

/*!
    \brief      format buffer array to fixed value, replace memset function
    \param[in,out]  buf: array to format
    \param[in]      data: value to be formatted as
    \param[in]      num: number of elements to format
    \retval     none
*/
void user_memset(void *buf, unsigned char data, unsigned char num) {
    unsigned char *buf_p = (unsigned char *) buf;
    for (unsigned char counter = 0; counter < num; ++counter)
        buf_p[counter] = data;
}
