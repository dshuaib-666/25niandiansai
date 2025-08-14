//#include "PID.h"                  // Device header


//const float Speed_Limit=7000;// 限定速度的大小，防止超越





//int16_t PID2_Carry(PID*pid,float purpose,float feedback){
//	
//	pid->previous_error=pid->last_error;
//	pid->last_error=pid->error;
//	pid->error=purpose-feedback;
//	
//	pid->pout=pid->kp*(pid->error-pid->last_error);
//	
//	pid->integral=pid->ki*pid->error;
//	
//	pid->dout=pid->kd*(pid->error-2*pid->last_error+pid->previous_error);

//	
//	pid->output=pid->pout+pid->integral+pid->dout;
//	pid->pwm=pid->output+feedback;

//	if(pid->pwm>Speed_Limit){
//	pid->pwm=Speed_Limit;
//	
//	}
//	else if(pid->pwm<-2000){
//	pid->pwm=-2000;
//		
//	}
//	return pid->pwm;
//}

//void PID1_Init(PID*pid,float KP,float KI,float KD){

//	pid->kp=KP;
//	pid->ki=KI;
//	pid->kd=KD;
//	pid->output=pid->dout=pid->integral=pid->pout=pid->error=pid->last_error=pid->previous_error=pid->pwm=0;




//}

//void PID2_Init(PID*pid,float KP,float KI,float KD){

//	pid->kp=KP;
//	pid->ki=KI;
//	pid->kd=KD;
//	pid->output=pid->dout=pid->integral=pid->pout=pid->error=pid->last_error=pid->previous_error=pid->pwm=0;




//}


//typedef struct
//{
//   	float kp, ki, kd; //????
//    float error, lastError; //???????
//    float integral, maxIntegral; //???????
//    float output, maxOutput; //???????
//}Location_PID1;
// 
////?????pid?????
//void Location_PID_Init(Location_PID *pid, float p, float i, float d, float maxI, float maxOut)
//{
//    pid->kp = p;
//    pid->ki = i;
//    pid->kd = d;
//    pid->maxIntegral = maxI;
//    pid->maxOutput = maxOut;
//}
// 
////????pid??
////???(pid???,???,???),??????pid????output???
//float PID_Calc(Location_PID *pid, float reference, float feedback)
//{
// 	//????
//    pid->lastError = pid->error; //??error???
//    pid->error = reference - feedback; //???error
//    //????
//    float dout = (pid->error - pid->lastError) * pid->kd;
//    //????
//    float pout = pid->error * pid->kp;
//    //????
//    pid->integral += pid->error * pid->ki;
//    //????

//	
//	
//    //????
//    pid->output = pout+dout + pid->integral;
//    //????
//    if(pid->output > pid->maxOutput) pid->output =   pid->maxOutput;
//    else if(pid->output < -pid->maxOutput) pid->output = -pid->maxOutput;
//	
//	return pid->output;
//}

//float Yaw2=0.0f;
//float PID2_Calc(Location_PID *pid, float reference, float feedback)
//{
// 	//????
//    pid->lastError = pid->error; //??error???
//    pid->error = reference - feedback; //???error
//    //????
//    float dout = (pid->error - pid->lastError) * pid->kd;
//    //????
//    float pout = pid->error * pid->kp;
//    //????
//    
//    //????
////////    if(Yaw1<1&&Yaw1>-3)
////////		{
////////		pid->integral=0;
////////		
////////		}
////////		else if(Yaw1<20&&Yaw1>-20)
////////		{
//////////		if(abs(((int)Yaw2-(int)Yaw1))>8)
//////////		{pid->integral=0;}
////////		pid->integral += pid->error * pid->ki;
////////		Yaw2=Yaw1;
////////		}
//    //????
//    pid->output = pout+dout + pid->integral;
//    //????
//    if(pid->output > pid->maxOutput) pid->output =   pid->maxOutput;
//    else if(pid->output < -pid->maxOutput) pid->output = -pid->maxOutput;
//	
//	return pid->output;
//}


////float Search_Start1(PID*pid){
////	
////	
////	  pid->previous_error=pid->last_error;
////	  pid->last_error=pid->error;
////	  
////	  if ((L3 == 1)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 10000
////    {
////        pid->error = -8.2;
////    }
////		else if ((L3 == 1)&& (L2 == 1) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 10000
////    {
////        pid->error = -8.2;
////    }
////		else if ((L3 == 0)&& (L2 == 0) && (L1 == 1) &&  (R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 01000
////    {
////        pid->error= -4.2;
////    }
////		else if ((L3 == 0)&& (L2 == 1) && (L1 == 1) &&  (R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 01000
////    {
////        pid->error= -4.2;
////    }
////		else if ((L3 == 0)&& (L2 == 0) && (L1 == 0) && (R1 == 1)&&(R2 == 0)  && (R3 == 0)) // 00010
////    {
////        pid->error =0.5;
////    }

////   	else if((L3 == 0)&& (L2 == 0) && (L1 == 0) && (R1 == 0)&&(R2 == 0)  && (R3 == 1)){
////		pid->error =2;
////		
////		}
////		else if((L3 == 0)&& (L2 == 0) && (L1 == 0) && (R1 == 0)&&(R2 == 1)  && (R3 == 0)){
////		pid->error =1;
////			
////		}
////		else if((L3 == 0)&& (L2 == 1) && (L1 == 0) && (R1 == 0)&&(R2 == 0)  && (R3 == 0)){
////		pid->error =-5.2;
////		
////		}
////		else if(M0L==0&&M0R==0){
////		pid->error =0;
////		
////		}
////		else if(M0L==1&&M0R==0){
////		pid->error =0;
////		
////		}
////		else if(M0L==0&&M0R==1){
////		pid->error =0;
////		
////		}
////		
////		
////		
////		
////	
////	
////	pid->pout=pid->kp*(pid->error-pid->last_error);
////	
////	pid->integral=pid->ki*pid->error;
////	
////	pid->dout=pid->kd*(pid->error-2*pid->last_error+pid->previous_error);

////		pid->output=pid->pout+pid->integral+pid->dout;

////    return pid->output;

////	}

////	
////	
////	
////float Search_Start2(PID*pid){
////	
////	
////	  pid->previous_error=pid->last_error;
////	  pid->last_error=pid->error;
////	  
////	  if ((L3 == 1)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 10000
////    {
////        pid->error = -10;
////    }
////		else if ((L3 == 1)&& (L2 == 1) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 10000
////    {
////        pid->error = -8;
////    }
////		else if((L3 == 0)&& (L2 == 1) && (L1 == 0) && (R1 == 0)&&(R2 == 0)  && (R3 == 0)){
////				
////				pid->error =-6;
////		}
////		else if ((L3 == 0)&& (L2 == 1) && (L1 == 1) &&  (R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 01000
////    {
////        pid->error= -4;
////    }
////		else if ((L3 == 0)&& (L2 == 0) && (L1 == 1) &&  (R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 01000
////    {
////        pid->error= -3;
////    }
////		else if ((L3 == 0)&& (L2 == 0) && (L1 == 0) && (R1 == 1)&&(R2 == 0)  && (R3 == 0)) // 00010
////    {
////        pid->error =0.5;
////    }

////   	else if((L3 == 0)&& (L2 == 0) && (L1 == 0) && (R1 == 0)&&(R2 == 0)  && (R3 == 1)){
////		pid->error =2;
////		
////		}
////		else if((L3 == 0)&& (L2 == 0) && (L1 == 0) && (R1 == 0)&&(R2 == 1)  && (R3 == 0)){
////		pid->error =1;
////			
////		}
////		
////		else if(M0L==0&&M0R==0){
////		pid->error =0;
////		
////		}
////		else if(M0L==1&&M0R==0){
////		pid->error =0;
////		
////		}
////		else if(M0L==0&&M0R==1){
////		pid->error =0;
////		
////		}
////		
////		 if ((L5==0)&&(L4!=0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5==0)) // 010000000
////	 {pid->error =-15;
////			
////		}
////		
////	else	 if ((L5!=0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5==0)) // 100000000
////		 {pid->error =-10;
////			
////		}
////	else if ((L5!=0)&&(L4!=0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5==0)) // 110000000
////	 {pid->error =-8;
////			
////		}
////	else if ((L5==0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4!=0)&&(R5==0)) // 000000010
////	 {pid->error =7;
////			
////		}
////	 else if ((L5==0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5!=0)) // 000000001
////	 {pid->error =11;
////			
////		}
////	else	 if ((L5==0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4!=0)&&(R5!=0)) // 000000011
////		 {pid->error =8;
////			
////		}
////		
////		
////	
////	
////	pid->pout=pid->kp*(pid->error-pid->last_error);
////	
////	pid->integral=pid->ki*pid->error;
////	
////	pid->dout=pid->kd*(pid->error-2*pid->last_error+pid->previous_error);

////		pid->output=pid->pout+pid->integral+pid->dout;

////    return pid->output;

////	}

////	float Search_track_Start2(PID*pid){
////	
////	
////	  pid->previous_error=pid->last_error;
////	  pid->last_error=pid->error;
////	  
////	  
////		
////		
////		
////	if ((L5!=0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5==0)) // 100000000
////	 {
////		 pid->error =-40;
////			
////		}
////	else if ((L5!=0)&&(L4!=0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5==0)) // 110000000
////	 {pid->error =-20;
////			
////		}
////	else if ((L5==0)&&(L4!=0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5==0)) // 010000000
////	 {pid->error =-15;
////			
////		}
////	  else if ((L5==0)&&(L4!=0)&&(L3 != 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5==0)) // 000000001
////	 {pid->error =-13;
////			
////		}
////	 else if ((L5==0)&&(L4==0)&&(L3 != 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5==0)) // 000000001
////	 {pid->error =-12;
////			
////		}
////	 else if ((L5==0)&&(L4==0)&&(L3 != 0)&& (L2 != 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5==0)) // 000000001
////	 {pid->error =-7;
////			
////		}
////	 
////		
////	else if ((L5==0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5!=0)) // 000000010
////	 {pid->error =40;
////			
////		}
////	else	 if ((L5==0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4!=0)&&(R5!=0)) // 000000011
////		 {pid->error =20;
////			
////		}
////	else if ((L5==0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4!=0)&&(R5==0)) // 000000001
////	 {pid->error =15;
////			
////		}
////	 else if ((L5==0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 != 0)&&(R4!=0)&&(R5==0)) // 000000001
////	 {pid->error =8;
////			
////		}
////	 else if ((L5==0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 != 0)&&(R4==0)&&(R5==0)) // 000000001
////	 {pid->error =6;
////			
////		}
////	 else if ((L5==0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 != 0)  && (R3!= 0)&&(R4==0)&&(R5==0)) // 000000001
////	 {pid->error =5;
////			
////		}
////	 else
////	 {
////	 pid->error =0;
////	 }
////	
////	 
////	
////		
////		
////	
////	
////	pid->pout=pid->kp*pid->error;
////	
////	pid->integral=pid->ki*pid->error;
////	
////	pid->dout=pid->kd*(pid->error-2*pid->last_error+pid->previous_error);

////		pid->output=pid->pout+pid->integral+pid->dout;

////    return pid->output;

////	}
////	

////	float Search_track_Start3(PID*pid){
////	
////	
////	  pid->previous_error=pid->last_error;
////	  pid->last_error=pid->error;
////	  
////	  
////		
////		
////		
////	if ((L5!=0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5==0)) // 100000000
////	 {
////		 pid->error =-40;
////			
////		}
////	else if ((L5!=0)&&(L4!=0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5==0)) // 110000000
////	 {pid->error =-20;
////			
////		}
////	else if ((L5==0)&&(L4!=0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5==0)) // 010000000
////	 {pid->error =-15;
////			
////		}
////	  else if ((L5==0)&&(L4!=0)&&(L3 != 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5==0)) // 000000001
////	 {pid->error =-8;
////			
////		}
////	 else if ((L5==0)&&(L4==0)&&(L3 != 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5==0)) // 000000001
////	 {pid->error =-6;
////			
////		}
////	 else if ((L5==0)&&(L4==0)&&(L3 != 0)&& (L2 != 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5==0)) // 000000001
////	 {pid->error =-5;
////			
////		}
////	 
////		
////	else if ((L5==0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5!=0)) // 000000010
////	 {pid->error =40;
////			
////		}
////	else	 if ((L5==0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4!=0)&&(R5!=0)) // 000000011
////		 {pid->error =20;
////			
////		}
////	else if ((L5==0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4!=0)&&(R5==0)) // 000000001
////	 {pid->error =15;
////			
////		}
////	 else if ((L5==0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 != 0)&&(R4!=0)&&(R5==0)) // 000000001
////	 {pid->error =8;
////			
////		}
////	 else if ((L5==0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 != 0)&&(R4==0)&&(R5==0)) // 000000001
////	 {pid->error =6;
////			
////		}
////	 else if ((L5==0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 != 0)  && (R3!= 0)&&(R4==0)&&(R5==0)) // 000000001
////	 {pid->error =5;
////			
////		}
////	 else
////	 {
////	 pid->error =0;
////	 }
////	
////	 
////	
////		
////		
////	
////	
////	pid->pout=pid->kp*pid->error;
////	
////	pid->integral=pid->ki*pid->error;
////	
////	pid->dout=pid->kd*(pid->error-2*pid->last_error+pid->previous_error);

////		pid->output=pid->pout+pid->integral+pid->dout;

////    return pid->output;

////	}
////		
////	
////	


////	
////float Search_Start3(PID*pid){
////	
////	
////	  pid->previous_error=pid->last_error;
////	  pid->last_error=pid->error;
////	  
////	  if ((L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 1)) // 10000
////    {
////        pid->error = 10;
////    }
////		else if ((L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 1)  && (R3 == 1)) // 10000
////    {
////        pid->error = 8;
////    }
////		else if((L3 == 0)&& (L2 == 0) && (L1 == 0) && (R1 == 0)&&(R2 == 1)  && (R3 == 0)){
////				
////				pid->error =6;
////		}
////		else if ((L3 == 0)&& (L2 == 0) && (L1 == 0) &&  (R1 == 1)&&(R2 == 1)  && (R3 == 0)) // 01000
////    {
////        pid->error= 4;
////    }
////		else if ((L3 == 0)&& (L2 == 0) && (L1 == 0) &&  (R1 == 1)&&(R2 == 0)  && (R3 == 0)) // 01000
////    {
////        pid->error= 3;
////    }
////		else if ((L3 == 0)&& (L2 == 0) && (L1 == 1) && (R1 == 0)&&(R2 == 0)  && (R3 == 0)) // 00010
////    {
////        pid->error =-0.5;
////    }

////   	else if((L3 == 1)&& (L2 == 0) && (L1 == 0) && (R1 == 0)&&(R2 == 0)  && (R3 == 0)){
////		pid->error =-2;
////		
////		}
////		else if((L3 == 0)&& (L2 == 1) && (L1 == 0) && (R1 == 0)&&(R2 == 0)  && (R3 == 0)){
////		pid->error =-1;
////			
////		}
////		
////		else if(M0L==0&&M0R==0){
////		pid->error =0;
////		
////		}
////		else if(M0L==1&&M0R==0){
////		pid->error =0;
////		
////		}
////		else if(M0L==0&&M0R==1){
////		pid->error =0;
////		
////		}
////		
////		 if ((L5==0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5!=0)) // 010000000
////	 {pid->error =15;
////			
////		}
////		
////	else	 if ((L5==0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4!=0)&&(R5!=0)) // 100000000
////		 {pid->error =10;
////			
////		}
////	else if ((L5==0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4!=0)&&(R5==0)) // 110000000
////	 {pid->error =8;
////			
////		}
////	else if ((L5==0)&&(L4!=0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5==0)) // 000000010
////	 {pid->error =-7;
////			
////		}
////	 else if ((L5!=0)&&(L4==0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5==0)) // 000000001
////	 {pid->error =-11;
////			
////		}
////	else	 if ((L5!=0)&&(L4!=0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(R1 == 0)&&(R2 == 0)  && (R3 == 0)&&(R4==0)&&(R5==0)) // 000000011
////		 {pid->error =-8;
////			
////		}
////		
////		
////	
////	
////	pid->pout=pid->kp*(pid->error-pid->last_error);
////	
////	pid->integral=pid->ki*pid->error;
////	
////	pid->dout=pid->kd*(pid->error-2*pid->last_error+pid->previous_error);

////		pid->output=pid->pout+pid->integral+pid->dout;

////    return pid->output;

////	}