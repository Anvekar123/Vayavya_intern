#include<Team_4.h>
#include<LPC21xx.h>

void configure_baudrate (unsigned int baud, float clock);

void configure_data_width (unsigned char data_length );

void configure_stop_bit (unsigned char stop);

void configure_parity (unsigned char par);

void transmit_data (unsigned char data);

int receive_data (unsigned char * data);




int main()

{
unsigned char msg[]={"BVB"}; // data to be sent

unsigned int rec_data=0;
PINSEL0 = 0xE002C000;
unsigned char * data;

configure_baudrate (9600, 20000000.0); //20MHz  // set baud rate-------????


configure_data_width (5); // 8 bit character 

configure_stop_bit (1); // 0x04 value or 1.0

configure_parity (1); // enable parity and set it to even parity (using enum)

while(rec_data==0)
{
for (int i=0;i<3;i++) {

transmit_data (msg[i]);

rev_data = receive_data (*data);

if(rev_data == 0){
printf("Error in receiving data");
break;
}
}
}

}
