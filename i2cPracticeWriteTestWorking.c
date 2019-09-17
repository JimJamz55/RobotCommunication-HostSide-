#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <linux/i2c.h>
#include <errno.h>
#include <glib-2.0/glib.h>

int main()
{
	int file;
	char *filename = "/dev/i2c-1";
	    const gchar *buffer;

	if((file = open(filename, O_RDWR)) < 0) 
	{
    		/* ERROR HANDLING: you can check errno to see what went wrong */
		perror("Failed to open the i2c bus");
                buffer = g_strerror(errno);
                printf("StdErr: %s", buffer);
                printf("\n\n");
    		exit(1);
	}
	printf("Bus has been opened\n");

	int addr = 0x54;
	//int addr = 0b01111111;          // The I2C address of the ADC
	//int addr = 0b01101011;
	//int addr = 0b00000000;
	if (ioctl(file, I2C_SLAVE, addr) < 0) 
	{
	    printf("Failed to acquire bus access and/or talk to slave.\n");
	    /* ERROR HANDLING; you can check errno to see what went wrong */
            buffer = g_strerror(errno);
            printf("StdErr: %s", buffer);
            printf("\n\n");
//	    exit(1);
	}
	printf("Communication has been initiated\n");
//	__u8 reg = 0x10; /* Device register to access */
//	unsigned char reg = 0x00;
	__s32 res;
	char buf[2];

	/*
	* Using I2C Write, equivalent of
	* i2c_smbus_write_word_data(file, reg, 0x6543)
	*/
	buf[0] = 0x00;
//	buf[1] = 0x01;
//	buf[2] = 0x00;
	buf[1] = 0x1E;
//	buf[2] = 0x1E;
	if (write(file, buf, 2) != 2) 
	{
		printf("write failed\n");
		buffer = g_strerror(errno);
		printf("StdErr: %s", buffer);
		printf("\n\n");
		// ERROR HANDLING: i2c transaction failed
	}
	printf("system write has been performed\n");
return 0;
}
