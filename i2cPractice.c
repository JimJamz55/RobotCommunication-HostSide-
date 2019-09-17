#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
//#include <glib.h>

int main()
{
	int file;
	char *filename = "/dev/i2c-1";
	if((file = open(filename, O_RDWR)) < 0) 
	{
    		/* ERROR HANDLING: you can check errno to see what went wrong */
		perror("Failed to open the i2c bus");
    		exit(1);
	}
	printf("Bus has been opened\n");

	//int addr = 0b00101001;          // The I2C address of the ADC
	int addr = 0b00100000;
	if (ioctl(file, I2C_SLAVE, addr) < 0) 
	{
	    printf("Failed to acquire bus access and/or talk to slave.\n");
	    /* ERROR HANDLING; you can check errno to see what went wrong */
	    exit(1);
	}
	printf("Communication has been initiated\n");
	__u8 reg = 0x10; /* Device register to access */
	__s32 res;
	char buf[1];

	close(file);
	if((file = open(filename, O_RDWR)) < 0)
        {
                /* ERROR HANDLING: you can check errno to see what went wrong */
                perror("Failed to open the i2c bus");
                exit(1);
        }
        printf("Bus has been opened\n");

	/*
	* Using I2C Write, equivalent of
	* i2c_smbus_write_word_data(file, reg, 0x6543)
	*/
	buf[0] = reg;
//	buf[1] = 0x00;
//	buf[2] = 0x00;
//	buf[1] = 0x43;
//	buf[2] = 0x65;
	int success = write(file, buf, 1);
        if(success != 1)	
	{
		printf("write failed\n");
		/* ERROR HANDLING: i2c transaction failed */
		printf("Error: %s\n", strerror(errno));
  	}
	printf("system write has been performed\n");
return 0;
}
