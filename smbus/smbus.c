#include <stdio.h>
#include <stdint.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <i2c/smbus.h>

int main()
{
int fd;
uint8_t command = 10;
uint16_t value = 16;
fd = open("/dev/i2c-4", O_RDWR);
ioctl(fd, I2C_SLAVE, 0x20);
//I2C_SLAVE_FORCE
i2c_smbus_write_word_data(fd, command, value);
i2c_smbus_read_word_data(fd, value);

printf("program completed\n");
return 0;
}
