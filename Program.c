#include<avr/io.h>
void cmd(int c);
void data(char d);
void delay();
void delay2();
void display(const char *p);
char rec();
char key();

void main()
{
int a,i,d=0,g=0,l=0,n,o,p,q,r,s,t;
char b[4]="1111",c[4],e[4]="2222",f[4],j[4]="3333",k[4],m[10];
DDRB=0XF0;
DDRC=0XFF;
DDRA=0XFF;
DDRD=0X04;
UCSRA=0X00;
UCSRB=0X18;
UCSRC=0X06;
UBRRH=0X00;
UBRRL=0X33;
cmd(0X38);
cmd(0X01);
cmd(0X80);
cmd(0X06);
cmd(0X0E);



while(1)
{
if((PIND&0X20)==0)
{
display("Two Wheeler");
cmd(0XC0);
display("Entering...");
cmd(0X01);
display("Enter pin");
cmd(0XC0);
for(i=0;i<4;i++)
{
c[i]=key();
data(c[i]);
}
cmd(0X01);
for(i=0;i<4;i++)
{
if(b[i]==c[i])
{
d++;
}
}
if(d==4)
{
display("APPROVED");
cmd(0X01);
display("Payment");
cmd(0XC0);
o=rec();
data(o);
p=rec();
data(p);
q=rec();
data(q);
cmd(0X01);
display("Balance");
o=o-1;
cmd(0XC0);
data(o);
data(p);
data(q);
cmd(0X01);
PORTA=0X41;
delay2();
PORTA=0X00;
delay2();
PORTA=0X42;
delay2();
PORTA=0X00;
cmd(0X01);
}
else
{
display("DENIED");
cmd(0X01);
}
}
else if((PIND&0X10)==0)
{
display("Four Wheeler");
cmd(0XC0);
display("Entering...");
cmd(0X01);
display("Enter pin");
cmd(0XC0);
for(i=0;i<4;i++)
{
f[i]=key();
data(f[i]);
}
cmd(0X01);
for(i=0;i<4;i++)
{
if(e[i]==f[i])
{
g++;
}
}
if(g==4)
{
display("APPROVED");
cmd(0X01);
display("Payment");
cmd(0XC0);
o=rec();
data(o);
p=rec();
data(p);
q=rec();
data(q);
cmd(0X01);
display("Balance");
o=o-2;
cmd(0XC0);
data(o);
data(p);
data(q);
cmd(0X01);
PORTA=0X44;
delay2();
PORTA=0X00;
delay2();
PORTA=0X48;
delay2();
PORTA=0X00;
cmd(0X01);
}
else
{
display("DENIED");
cmd(0X01);
}
}
else if((PIND&0X08)==0)
{
display("Heavy Vehicle");
cmd(0XC0);
display("Entering...");
cmd(0X01);
display("Enter pin");
cmd(0XC0);
for(i=0;i<4;i++)
{
k[i]=key();
data(k[i]);
}
cmd(0X01);
for(i=0;i<4;i++)
{
if(j[i]==k[i])
{
l++;
}
}
if(l==4)
{
display("APPROVED");
cmd(0X01);
display("Payment");
cmd(0XC0);
o=rec();
data(o);
p=rec();
data(p);
q=rec();
data(q);
cmd(0X01);
display("Balance");
o=o-3;
cmd(0XC0);
data(o);
data(p);
data(q);
cmd(0X01);
PORTA=0X50;
delay2();
PORTA=0X00;
delay2();
PORTA=0X60;
delay2();
PORTA=0X00;
cmd(0X01);
}
else
{
display("DENIED");
cmd(0X01);
}
}
}
}

char rec()
{

while((UCSRA&0X80)==0);
delay();
return(UDR);

}

char key()
{
int e;
while(1)
{
PORTB=0X7F;
e=PINB&0X0F;
switch(e)
{  
case 0X07:return('1');break;
case 0X0B:return('2');break;
case 0X0D:return('3');break;
case 0X0E:return('4');break;
}
PORTB=0XBF;
e=PINB&0X0F;
switch(e)
{
case 0X07:return('5');break;
case 0X0B:return('6');break;
case 0X0D:return('7');break;
case 0X0E:return('8');break;
}
PORTB=0XDF;
e=PINB&0X0F;
switch(e)
{
case 0X07:return('9');break;
case 0X0B:return('A');break;
case 0X0D:return('B');break;
case 0X0E:return('C');break;
}
PORTB=0XEF;
e=PINB&0X0F;
switch(e)
{
case 0X07:return('D');break;
case 0X0B:return('E');break;
case 0X0D:return('F');break;
case 0X0E:return('G');break;
}
}
}
void cmd(int c)
{
PORTC=c;
PORTD=0X00;
PORTA=0X40;
delay();
PORTA=0X00;
}
void data(char d)
{
PORTC=d;
PORTD=0X04;
PORTA=0X40;
delay();
PORTA=0X00;
}
void delay()
{
int i,j;
for(i=0;i<300;i++)
for(j=0;j<300;j++);
}
void delay2()
{
int i,j;
for(i=0;i<800;i++)
for(j=0;j<800;j++);
}
void display(const char *p)
{
while(*p!='\0')
{
data(*p);
p++;
}
}





