#ifndef _BSP_IIC_H__
#define _BSP_IIC_H__

#include "board.h"

//����SDA���ģʽ
#define SDA_OUT()   {                                                  \
                        DL_GPIO_initDigitalOutput(IIC_Software_SDA_IOMUX);     \
                        DL_GPIO_setPins(IIC_Software_PORT, IIC_Software_SDA_PIN);      \
                        DL_GPIO_enableOutput(IIC_Software_PORT, IIC_Software_SDA_PIN); \
                    }
//����SDA����ģʽ
#define SDA_IN()    { DL_GPIO_initDigitalInput(IIC_Software_SDA_IOMUX); }

//��ȡSDA���ŵĵ�ƽ�仯
#define SDA_GET()   ( ( ( DL_GPIO_readPins(IIC_Software_PORT,IIC_Software_SDA_PIN) & IIC_Software_SDA_PIN ) > 0 ) ? 1 : 0 )
//SDA��SCL���
#define SDA(x)      ( (x) ? (DL_GPIO_setPins(IIC_Software_PORT,IIC_Software_SDA_PIN)) : (DL_GPIO_clearPins(IIC_Software_PORT,IIC_Software_SDA_PIN)) )
#define SCL(x)      ( (x) ? (DL_GPIO_setPins(IIC_Software_PORT,IIC_Software_SCL_PIN)) : (DL_GPIO_clearPins(IIC_Software_PORT,IIC_Software_SCL_PIN)) )


uint8_t IICwriteBytes(uint8_t addr,uint8_t regaddr,uint8_t num,uint8_t *regdata);
uint8_t IICreadBytes(uint8_t addr, uint8_t regaddr,uint8_t num,uint8_t* Read);
#endif
