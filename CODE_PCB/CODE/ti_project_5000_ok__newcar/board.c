
#include "stdio.h"
#include "CSZ_ALL.h"
#include <stdarg.h>
#define RE_0_BUFF_LEN_MAX	128

volatile uint8_t  recv0_buff[RE_0_BUFF_LEN_MAX] = {0};
volatile uint16_t recv0_length = 0;
volatile uint8_t  recv0_flag = 0;

void board_init(void)
{
	SYSCFG_DL_init();
	
//	printf("Board Init [[ ** LCKFB ** ]]\r\n");
}

//搭配滴答定时器实现的精确us延时
void delay_us(unsigned long __us) 
{
    uint32_t ticks;
    uint32_t told, tnow, tcnt = 38;

    // 计算需要的时钟数 = 延迟微秒数 * 每微秒的时钟数
    ticks = __us * (80000000 / 1000000);

		// 获取当前的SysTick值
		told = SysTick->VAL;

    while (1)
    {
        // 重复刷新获取当前的SysTick值
        tnow = SysTick->VAL;

        if (tnow != told)
        {
            if (tnow < told)
                tcnt += told - tnow;
            else
                tcnt += SysTick->LOAD - tnow + told;

            told = tnow;

            // 如果达到了需要的时钟数，就退出循环
            if (tcnt >= ticks)
                break;
        }
    }
}
//搭配滴答定时器实现的精确ms延时
void delay_ms(unsigned long ms) 
{
	delay_us( ms * 1000 );
}

void delay_1us(unsigned long __us){ delay_us(__us); }
void delay_1ms(unsigned long ms){ delay_ms(ms); }

void uart0_send_char(char ch)
{
	while( DL_UART_isBusy(UART_0_DEBUG_INST) == true );
	DL_UART_Main_transmitData(UART_0_DEBUG_INST, ch);

}
void uart0_send_string(char* str)
{
	while(*str!=0&&str!=0)
	{
		uart0_send_char(*str++);
	}
}
void uart3_send_char(char ch)
{
	while( DL_UART_isBusy(UART_3_INST) == true );
	DL_UART_Main_transmitData(UART_3_INST, ch);

}
void uart3_send_string(char* str)
{
	while(*str!=0&&str!=0)
	{
		uart3_send_char(*str++);
	}
}
void UART_printf(const char *format, ...) {
  uint32_t length;
  va_list args;
  uint32_t i;
  char TxBuffer[128] = {0};

  va_start(args, format);
  length = vsnprintf((char *)TxBuffer, sizeof(TxBuffer), (char *)format, args);
  va_end(args);

  for (i = 0; i < length; i++) {
    DL_UART_Main_transmitDataBlocking(UART_0_DEBUG_INST, TxBuffer[i]);
  }
}


#if !defined(__MICROLIB)
#if (__ARMCLIB_VERSION <= 6000000)
struct __FILE
{
	int handle;
};
#endif

FILE __stdout;

void _sys_exit(int x)
{
	x = x;
}
#endif


int fputc(int _c, FILE *_fp) {
  DL_UART_Main_transmitDataBlocking(UART_0_DEBUG_INST, _c);
  return _c;
}

int fputs(const char *restrict s, FILE *restrict stream) {
  uint16_t i, len;
  len = strlen(s);
  for (i = 0; i < len; i++) {
    DL_UART_Main_transmitDataBlocking(UART_0_DEBUG_INST, s[i]);
  }
  return len;
}

int puts(const char *_ptr) {
  int cnt = fputs(_ptr, stdout);
  cnt += fputs("\n", stdout);
  return cnt;
}


