#include "bsp_track.h"
HUIDUPID huidupid;


HUIDU huidu;
int64_t num = 0;





//º¯Êý
//¶ÁÈ¡Ñ­¼£Ä£¿é
uint8_t* Data;
uint8_t* Inrared_Get(void)
{
	   
				
		int i=0;
		static uint8_t Infr_data[8];
		
		DL_GPIO_clearPins(GPIOB,DL_GPIO_PIN_26);//SH
		delay_us(2);
		DL_GPIO_setPins(GPIOB,DL_GPIO_PIN_26);
		delay_us(2);		
		for(i=0; i<8
	
	
	
	; i++)
		{
			DL_GPIO_clearPins(GPIOB,DL_GPIO_PIN_9);
			if(DL_GPIO_readPins(GPIOB, DL_GPIO_PIN_13)!=0)
			{
				Infr_data[i]=1;
			}
			else
			{
			  Infr_data[i]=0;
			}
			delay_us(2);
			DL_GPIO_setPins(GPIOB,DL_GPIO_PIN_9);
			delay_us(2);
		}
		return Infr_data;
}


//float HUIDU_SHIBIE(HUIDUPID*pid){
//	
//	
//	  pid->previous_error=pid->last_error;
//	  pid->last_error=pid->error;
//	  if ((L3 != 0)&& (L2 == 0) && (L1 == 0)&&(ML == 0)&&(MR == 0)  &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 001000000
//    {
//        pid->error = -10;
//    }
//		else if ((L3 != 0)&& (L2 != 0) && (L1 == 0) &&(ML == 0)&&(MR == 0)&&(R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 10000
//    {
//        pid->error = -9.2;
//    }
//		else if((L3 ==  0)&& (L2 != 0) && (L1 == 0) &&(ML == 0)&&(MR == 0)&& (R1 == 0)&&(R2 == 0)  && (R3 == 0))
//		{
//				pid->error =-8.7;
//		}
//		else if ((L3 == 0)&& (L2 != 0) && (L1 != 0)&&(ML == 0)&&(MR == 0) &&  (R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 01000
//    {
//        pid->error= -8;
//    }
//		else if ((L3 == 0)&& (L2 == 0) && (L1 != 0) &&(ML == 0)&&(MR == 0)&&  (R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 01000
//    {
//        pid->error= -7.4;
//    }
//		else if ((L3 == 0)&& (L2 == 0) && (L1 != 0) &&(ML != 0)&&(MR == 0)&&  (R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 01000
//    {
//        pid->error= -6;
//    }		
//		else if ((L3 == 0)&& (L2 == 0) && (L1 == 0) &&(ML != 0)&&(MR == 0)&&  (R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 01000
//    {
//        pid->error= -4;
//    }		
//		else if ((L3 == 0)&& (L2 == 0) && (L1 == 0) &&(ML == 0)&&(MR != 0)&&  (R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 01000
//    {
//        pid->error= 4;
//    }	
//		else if ((L3 == 0)&& (L2 == 0) && (L1 == 0) &&(ML == 0)&&(MR != 0)&&  (R1 != 0)&&(R2 == 0)  && (R3 == 0)) // 01000
//    {
//        pid->error= 6;
//    }				
//		else if ((L3 == 0)&& (L2 == 0) && (L1 == 0) &&(ML == 0)&&(MR == 0)&&  (R1 != 0)&&(R2 == 0)  && (R3 == 0)) // 01000
//    {
//        pid->error= 7.4;
//    }		
//		else if ((L3 == 0)&& (L2 == 0) && (L1 == 0) &&(ML == 0)&&(MR == 0)&&  (R1 != 0)&&(R2 != 0)  && (R3 == 0)) // 01000
//    {
//        pid->error= 8;
//    }				
//		else if ((L3 == 0)&& (L2 == 0) && (L1 == 0) &&(ML == 0)&&(MR == 0)&&  (R1 == 0)&&(R2 != 0)  && (R3 == 0)) // 01000
//    {
//        pid->error= 8.7;
//    }				
//		else if ((L3 == 0)&& (L2 == 0) && (L1 == 0) &&(ML == 0)&&(MR == 0)&&  (R1 == 0)&&(R2 != 0)  && (R3 != 0)) // 01000
//    {
//        pid->error= 20;
//    }				
//		else if ((L3 == 0)&& (L2 == 0) && (L1 == 0) &&(ML == 0)&&(MR == 0)&&  (R1 == 0)&&(R2 == 0)  && (R3 != 0)) // 01000
//    {
//        pid->error= 30;
//    }			
//		else
//		{
//		pid->error= 0;
//		
//		}

//	pid->pout=pid->kp*(pid->error-pid->last_error);
//	
//	pid->integral=pid->ki*pid->error;
//	
//	pid->dout=pid->kd*(pid->error-2*pid->last_error+pid->previous_error);

//		pid->output=pid->pout+pid->integral+pid->dout;

//    return pid->output;


//	}







float HUIDU_SHIBIE(HUIDUPID*pid){
	
	
	  pid->previous_error=pid->last_error;
	  pid->last_error=pid->error;
		if ((L4 != 0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0)&&(ML == 0)&&(MR == 0)  &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 001000000
    {
        pid->error = -19;
    }
	 if ((L4 != 0)&&(L3 != 0)&& (L2 == 0) && (L1 == 0)&&(ML == 0)&&(MR == 0)  &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 001000000
    {
        pid->error = -17;
    }
	 else if ((L4 == 0)&&(L3 != 0)&& (L2 == 0) && (L1 == 0)&&(ML == 0)&&(MR == 0)  &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 001000000
    {
        pid->error = -16;
    }
		else if ((L4 == 0)&&(L3 != 0)&& (L2 != 0) && (L1 == 0) &&(ML == 0)&&(MR == 0)&&(R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 10000
    {
        pid->error = -15;
    }
		else if((L4 == 0)&&(L3 ==  0)&& (L2 != 0) && (L1 == 0) &&(ML == 0)&&(MR == 0)&& (R1 == 0)&&(R2 == 0)  && (R3 == 0))
		{
				pid->error =-12;
		}
		else if ((L4 == 0)&&(L3 == 0)&& (L2 != 0) && (L1 != 0)&&(ML == 0)&&(MR == 0) &&  (R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 01000
    {
        pid->error= -11;
    }
		else if ((L4 == 0)&&(L3 == 0)&& (L2 == 0) && (L1 != 0) &&(ML == 0)&&(MR == 0)&&  (R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 01000
    {
        pid->error= -9;
    }
		else if ((L4 == 0)&&(L3 == 0)&& (L2 == 0) && (L1 != 0) &&(ML != 0)&&(MR == 0)&&  (R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 01000
    {
        pid->error= -5;
    }		
		else if ((L4 == 0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(ML != 0)&&(MR == 0)&&  (R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 01000
    {
        pid->error= -3;
    }		
		else if ((L4 == 0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(ML == 0)&&(MR != 0)&&  (R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 01000
    {
        pid->error= 3;
    }	
		else if ((L4 == 0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(ML == 0)&&(MR != 0)&&  (R1 != 0)&&(R2 == 0)  && (R3 == 0)) // 01000
    {
        pid->error= 5;
    }				
		else if ((L4 == 0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(ML == 0)&&(MR == 0)&&  (R1 != 0)&&(R2 == 0)  && (R3 == 0)) // 01000
    {
        pid->error= 7;
    }		
		else if ((L4 == 0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(ML == 0)&&(MR == 0)&&  (R1 != 0)&&(R2 != 0)  && (R3 == 0)) // 01000
    {
        pid->error= 9;
    }				
		else if ((L4 == 0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(ML == 0)&&(MR == 0)&&  (R1 == 0)&&(R2 != 0)  && (R3 == 0)) // 01000
    {
        pid->error= 11;
    }				
		else if ((L4 == 0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(ML == 0)&&(MR == 0)&&  (R1 == 0)&&(R2 != 0)  && (R3 != 0)) // 01000
    {
        pid->error= 12;
    }				
		else if ((L4 == 0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(ML == 0)&&(MR == 0)&&  (R1 == 0)&&(R2 == 0)  && (R3 != 0)) // 01000
    {
        pid->error= 16;
    }		
		


	pid->pout=pid->kp*(pid->error-pid->last_error);
	
	pid->integral=pid->ki*pid->error;
	
	pid->dout=pid->kd*(pid->error-2*pid->last_error+pid->previous_error);

		pid->output=pid->pout+pid->integral+pid->dout;

    return pid->output;


	}