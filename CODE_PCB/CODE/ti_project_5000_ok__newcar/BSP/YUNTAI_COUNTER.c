#include "CSZ_ALL.h"
//ʹ������ʽ
 //smotor_info X_LOCATION_PID = {1.3f, 0.3f, 0.005f, 0, 0, 0, 0, 0, 33};//���pid
 smotor_info X_LOCATION_PID = {3.5f, 0.7f, 0, 0, 0, 0, 0, 0, 33};//���pid 0.2
 smotor_info Y_LOCATION_PID = {0.5f, 0.5f,20.0f, 0, 0, 0, 0, 0, 33};//���pid 
 //׷Ŀ�꼤��PID ��λ��ʽ�Ѿ����ã�
  smotor_info X_LOCATION_PID_NEW = {4.5f, 0.0f, 0.5f, 0, 0, 0, 0, 0, 33};//���pid
  smotor_info Y_LOCATION_PID_NEW = {0.3f, 0.0f, 1.0f, 0, 0, 0, 0, 0, 33};//���pid
	
	
	 //׷Ŀ�꼤��PID ��λ��ʽ�Ѿ����ã�
  smotor_info X_LOCATION_PID_FOUR = {8.0f, 0.0f, 0.0f, 0, 0, 0, 0, 0, 33};//���pid
  smotor_info Y_LOCATION_PID_FOUR = {0.3f, 0.0f, 1.0f, 0, 0, 0, 0, 0, 33};//���pid
  //��λPID����
  smotor_info X_LOCATION_PID_YUNTAI = {-0.05f, -0.005f, -0.0f, 0, 0, 0, 0, 0, 33};//���pid
  smotor_info Y_LOCATION_PID_YUNTAI = {-0.05f, -0.005f, -0.0f, 0, 0, 0, 0, 0, 33};//���pid 
 LOCATION location;
 int X_DATE,Y_DATE;

DEBUG_DATA debug_data;
	
	
	
	
 void Location_DATA_init(void)
 {
	 location.XOUT=0;
	 location.YOUT=0;
	 location.X_BIA=0;
	 location.Y_BIA=0;
 location.xunji_counter=0;
 }
 
//�����ֵ
//������ 
void LOCATION_X(int sumber)//xֵ��ʾ������
{
	if(sumber>0)
	{
	BUJIN_COUNTER(X,XSHUN,1000,sumber);
	
	}
	else if(sumber<=0)
	{
		sumber=-sumber;
	BUJIN_COUNTER(X,XNI,1000,sumber);
	
	}
}

void LOCATION_X_FOUR(int sumber)//xֵ��ʾ������
{
	if(sumber>0)
	{
	BUJIN_COUNTER_FOUR(X,XSHUN,2000,sumber);
	
	}
	else if(sumber<=0)
	{
		sumber=-sumber;
	BUJIN_COUNTER_FOUR(X,XNI,2000,sumber);
	
	}
}

void LOCATION_X_FOUR_NEW(int sumber)//xֵ��ʾ������
{
	if(sumber>0)
	{
	BUJIN_COUNTER_FOUR(X,XSHUN,3000,sumber);
	
	}
	else if(sumber<=0)
	{
		sumber=-sumber;
	BUJIN_COUNTER_FOUR(X,XNI,3000,sumber);
	
	}
}

//y��ʹ�õľ��Ե�λ�ã�����Ϊ
void LOCATION_Y(int sumber)//yֵ��ʾ������
{
	if(sumber>0)
	{
	BUJIN_COUNTER(Y, YZHENG,100,sumber);
	
	}
	else if(sumber<=0)
	{
		sumber=-sumber;
	BUJIN_COUNTER(Y,YFU,100,sumber);
	
	}

	
	
}
	
 
 
 
 
 
 //403��ʱ���ʾx���м���
 
 void Location_PID_X_TWO(void)
{
				if(k230.RED_x==0)
				{
					return ;
				
				
				}
//				
//				if(403.0f-X_DATE>-10.0f&&403.0f-X_DATE<10.0f)
//				{
//					 location.X_BIA=0; 
//				}
//				else{
//					location.X_BIA=403.0f-X_DATE;
//				}
//				
//	
			   location.X_BIA=k230.RED_x-420.0f;
				location.X_Error2=location.X_Error1;
				location.X_Error1= location.X_Error0;
				location.X_Error0= location.X_BIA;
				
				location.X_DOUT=(location.X_Error0-2*location.X_Error1+location.X_Error2);
				
				if(location.X_BIA>8||location.X_BIA<-8)
				{
				   X_LOCATION_PID.ki=2.0f;
				
				}
				else{
					  X_LOCATION_PID.ki=0;
				}
			//	X_LOCATION_PID.ki=2.0f;
				location.XOUT=X_LOCATION_PID.kp*(location.X_Error0-location.X_Error1)+X_LOCATION_PID.ki*location.X_Error0+X_LOCATION_PID.kd*location.X_DOUT;
				
//				if(location.XOUT>45){location.XOUT=45;}
//				if(location.XOUT<-45){location.XOUT=-45;}
				
				LOCATION_X(location.XOUT);
//				duoji.duoji_down=location.XOUT;
//			DUOJI_LOCATION_X(duoji.duoji_down) ;
				//LOCATION_X(location.XOUT);
				
			
}

 void Location_PID_X_NEW(void)
{
				if(k230.RED_x==0)
				{
					return ;
				
				
				}

//	
//			    location.X_BIA=k230.RED_x-k230.GREEN_x;
				 location.X_BIA=k230.RED_x-410.0f;//���Ӵ�������
				location.X_Error1= location.X_Error0;
				location.X_Error0= location.X_BIA;
				
				
				
				
				location.X_DOUT=(location.X_Error0-location.X_Error1);
				
//				 if(location.X_BIA<100&&location.X_BIA>-100)
//				{
//					location.X_ErrorInt+= location.X_Error0;
//				   
//				
//				}
//				else{
//					 
//					location.X_ErrorInt=0;
//				}
					
				if(location.X_BIA>6||location.X_BIA<-6)
				{
				location.XOUT=X_LOCATION_PID_NEW.kp*location.X_Error0+X_LOCATION_PID_NEW.ki*location.X_ErrorInt+X_LOCATION_PID_NEW.kd*location.X_DOUT;
				}
				else{location.XOUT=0;
				}
		LOCATION_X(location.XOUT);
				
				//LOCATION_X(location.XOUT);
				
//				duoji.duoji_down=location.XOUT;
//			DUOJI_LOCATION_X(duoji.duoji_down) ;
			
}
 void Location_PID_X_FOUR(void)
{
				if(k230.RED_x==0)
				{
					return ;
				
				
				}

//	
//			    location.X_BIA=k230.RED_x-k230.GREEN_x;
				 location.X_BIA=k230.RED_x-415.0f;//���Ӵ�������
				location.X_Error1= location.X_Error0;
				location.X_Error0= location.X_BIA;
				
				
				
				
				location.X_DOUT=(location.X_Error0-location.X_Error1);
				
//				 if(location.X_BIA<100&&location.X_BIA>-100)
//				{
//					location.X_ErrorInt+= location.X_Error0;
//				   
//				
//				}
//				else{
//					 
//					location.X_ErrorInt=0;
//				}
					
			
				location.XOUT=X_LOCATION_PID_FOUR.kp*location.X_Error0+X_LOCATION_PID_FOUR.ki*location.X_ErrorInt+X_LOCATION_PID_FOUR.kd*location.X_DOUT;
				
				//location.XOUT=0;
				
		LOCATION_X_FOUR_NEW(location.XOUT);
				
				//LOCATION_X(location.XOUT);
				
//				duoji.duoji_down=location.XOUT;
//			DUOJI_LOCATION_X(duoji.duoji_down) ;
			
}
 void Location_PID_Y_TWO(void)
{
				if(k230.RED_y==0)
				{
					return ;
				
				
				}
				
//				if(220.0f-Y_DATE>-5&&220.0f-Y_DATE<5.0f)
//				{
//					 location.Y_BIA=0; 
//				}
//				else{
//					location.Y_BIA=220.0f-Y_DATE;
//				}
				//location.Y_BIA=233.0f-Y_DATE;  //�õ�ƫ��ֵ
	
		   	//location.Y_BIA=235.0f-k230.RED_y;
				location.Y_BIA=210.0f-k230.RED_y;//���ֵԽСԽ����
				location.Y_Error2=location.Y_Error1;
				location.Y_Error1= location.Y_Error0;
				location.Y_Error0= location.Y_BIA;
				//��ߵ�Խ�󴰿�����
				if(location.Y_BIA>0||location.Y_BIA<-10)
				{
				   Y_LOCATION_PID.ki=1.0f;
				
				}
				else{
					  Y_LOCATION_PID.ki=0.0f;
				}
				location.location_OLD_D=0.5f*(location.Y_Error0-2*location.Y_Error1+location.Y_Error2)+0.5f*location.location_OLD_D;
				location.YOUT=Y_LOCATION_PID.kp*(location.Y_Error0-location.Y_Error1)+Y_LOCATION_PID.ki*location.Y_Error0+Y_LOCATION_PID.kd*location.location_OLD_D;
		LOCATION_Y(location.YOUT);
//				if(location.YOUT>45){location.YOUT=45;}
//				if(location.YOUT<-45){location.YOUT=-45;}
//				 DUOJI_UP(location.YOUT);
}


 void Location_PID_Y_NEW(void)
{
				if(k230.RED_y==0)
				{
					return ;
				
				
				}

	//			Խ��Խ����
			    location.Y_BIA=235.0f-k230.RED_y;
				location.Y_Error1= location.Y_Error0;
				location.Y_Error0= location.Y_BIA;
				
				
				
				
				location.Y_DOUT=(location.Y_Error0-location.Y_Error1);
				
				 if(location.Y_BIA<10&&location.Y_BIA>-10)
				{
					location.Y_ErrorInt+= location.Y_Error0;
				   
				
				}
				else{
					 
					location.Y_ErrorInt=0;
				}
					
				if(location.Y_BIA>8||location.Y_BIA<-8)
				{
				location.YOUT=Y_LOCATION_PID_NEW.kp*location.Y_Error0+Y_LOCATION_PID_NEW.ki*location.Y_ErrorInt+Y_LOCATION_PID_NEW.kd*location.Y_DOUT;
				}
				else{location.YOUT=0;
				}
						LOCATION_Y(location.YOUT);
			
}

 void Location_PID_Y_FOUR(void)
{
				if(k230.RED_y==0)
				{
					return ;
				
				
				}

	
			    location.Y_BIA=217.0f-k230.RED_y;
				location.Y_Error1= location.Y_Error0;
				location.Y_Error0= location.Y_BIA;
				
				
				
				
				location.Y_DOUT=(location.Y_Error0-location.Y_Error1);
				
				 if(location.Y_BIA<10&&location.Y_BIA>-10)
				{
					location.Y_ErrorInt+= location.Y_Error0;
				   
				
				}
				else{
					 
					location.Y_ErrorInt=0;
				}
					
				if(location.Y_BIA>8||location.Y_BIA<-8)
				{
				location.YOUT=Y_LOCATION_PID_NEW.kp*location.Y_Error0+Y_LOCATION_PID_NEW.ki*location.Y_ErrorInt+Y_LOCATION_PID_NEW.kd*location.Y_DOUT;
				}
				else{location.YOUT=0;
				}
						LOCATION_Y(location.YOUT);
			
}
//���뵱ǰ�����꣬�Լ�Ŀǰ�����꣬���Լ�����ȥ���൱��λ�û�
void location_POINT_PID_X(float NOW_X,float TARGET_X)
{
				if(NOW_X==0)//ֻ��Ҫ��������
				{
					return ;
				}

	
			    location.location_PID_X_BIA=NOW_X-TARGET_X ;
				location.location_PID_X_Error1= location.location_PID_X_Error0;
				location.location_PID_X_Error0= location.location_PID_X_BIA;
				
				
				
				
				location.location_PID_X_DOUT=(location.location_PID_X_Error0-location.location_PID_X_Error1);
				
				 if(location.location_PID_X_BIA<100&&location.location_PID_X_BIA>-100)
				{
					location.location_PID_X_ErrorInt+= location.location_PID_X_Error0;
				   
				
				}
				else{
					 
					location.location_PID_X_ErrorInt=0;
				}
					
				
				location.location_PID_XOUT=X_LOCATION_PID_YUNTAI.kp*location.location_PID_X_Error0+X_LOCATION_PID_YUNTAI.ki*location.location_PID_X_ErrorInt+X_LOCATION_PID_YUNTAI.kd*location.location_PID_X_DOUT;
				
				if(location.location_PID_XOUT>45){location.location_PID_XOUT=45;}
				if(location.location_PID_XOUT<-45){location.location_PID_XOUT=-45;}
//				duoji.duoji_down=location.location_PID_XOUT;
//				DUOJI_LOCATION_X(duoji.duoji_down) ;



}
void YUANDIXUANZHUAN(void)
{
	//	LOCATION_X(location.xuanzhuan_angle);
		if(location.xuanzhuan_angle<14000)
		{
			location.xuanzhuan_angle+=40;
			LOCATION_X(200);
		}
		
}
//���뵱ǰ�����꣬�Լ�Ŀǰ�����꣬���Լ�����ȥ���൱��λ�û�
void location_POINT_PID_Y(float NOW_Y,float TARGET_Y)
{
				if(NOW_Y==0)//ֻ��Ҫ��������
				{
					return ;
				}

	
			    location.location_PID_Y_BIA=NOW_Y-TARGET_Y ;
				location.location_PID_Y_Error1= location.location_PID_Y_Error0;
				location.location_PID_Y_Error0= location.location_PID_Y_BIA;
				
				
				
				
				location.location_PID_X_DOUT=(location.location_PID_Y_Error0-location.location_PID_Y_Error1);
				
				 if(location.location_PID_Y_BIA<100&&location.location_PID_Y_BIA>-100)
				{
					location.location_PID_Y_ErrorInt+= location.location_PID_Y_Error0;
				   
				
				}
				else{
					 
					location.location_PID_Y_ErrorInt=0;
				}
					
				
				location.location_PID_YOUT=Y_LOCATION_PID_YUNTAI.kp*location.location_PID_Y_Error0+Y_LOCATION_PID_YUNTAI.ki*location.location_PID_Y_ErrorInt+Y_LOCATION_PID_YUNTAI.kd*location.location_PID_Y_DOUT;
				
				if(location.location_PID_YOUT>45){location.location_PID_YOUT=45;}
				if(location.location_PID_YOUT<-45){location.location_PID_YOUT=-45;}
//				duoji.duoji_up=location.location_PID_YOUT;
//				DUOJI_LOCATION_Y(duoji.duoji_up) ;



}
void location_POINT_PID(float NOW_X,float NOW_Y,float TARGET_X,float TARGET_Y)
{
			



}







