
#ifndef TSERIAL_H
#define TSERIAL_H
 
#include <stdio.h>
#include <windows.h>
 
 
enum serial_parity  
{
 spNONE,spODD, spEVEN 
};


class Tserial
{
protected:
    char              port[10];                      // 端口名称“com1”，...
    int               rate;                          // 波特率
    serial_parity     parityMode;
    HANDLE            serial_handle;                 // ...
 

public:
                  Tserial();
                 ~Tserial();
    int           connect          (char *port_arg, int rate_arg,serial_parity parity_arg); //连接
    void          sendChar         (char c);                                                //发送一个char
    void          sendArray        (char *buffer, int len);                                 //发送一个数组
    char          getChar          (void);                                                  //获取一个char
    int           getArray         (char *buffer, int len);                                 //获取一个数组
    int           getNbrOfBytes    (void);
    void          disconnect       (void);                                                  //断开连接
 
};

 
#endif TSERIAL_H



/*
演示过程：

com = new Tserial();//创建串口对象
	if (com != 0)
	{
		com->connect(const_cast<char*>("COM4"), 57600, spNONE);//设置串口，波特率
		printf_s("串口打开成功\n")； 
	}
 com->sendChar(MSB);//发送一个字节
 com->disconnect();//关闭串口

 */