#include<Servo.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);      //INITIALIZING LCD IN 4-BIT MODE
char c[15]={"-Raghul,Venkat"};
String s;
int pos=0;
Servo servo;
bool intro = true;
bool concheck = true;

void setup()
{
lcd.begin(16 , 2);
lcd.clear();
pinMode(A0,INPUT);
pinMode(8,INPUT);
pinMode(9,OUTPUT);
servo.attach(10);
servo.write(0);
}
void loop()
{
  int from = digitalRead(8);
  if(from == LOW)
  {
    servo.write(0);
  }
  else
  {
  for (pos; pos <= 90; pos += 1) 
  { 
    servo.write(pos);              
    delay(15);
    
  }
  if(concheck == true)
  {
   conn();
  }
  delay(3000);
  if(intro == true)
  {
   namestamp();
   intro = false;
  }
  delay(3000);
  emergencystop();
  }
 
}
void emergencystop()
{
  int value = analogRead(A0);
  //String valu = value.toString(); 
  
  lcd.print(value);
  
  if(value<100)
  {
    digitalWrite(9,HIGH);
  }
  
}
void conn()
{
  delay(3000);
  lcd.print("conn estd");
  concheck = false;
}
void namestamp()
{
  int i,j,k=0,l=0;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("ARRV Manipulator");
delay(1000);
for(i=14;i>=0;i--)
{
  k=0;
  for(j=i;j<=13;j++)
  {
  lcd.setCursor(j,1);
  lcd.print(c[k]);
  delay(90);
  k++;
  if(i==0 && j==13)
  goto xyz;              //IF string reaches the first matrix drop each character one by one
                         //so it feels that the string is terminating
  }
}
xyz: 
if(i==0 && j==13)
      {
        while(k!=0)
           {
        lcd.setCursor(0,1);
        for(i=k;i>=2;i--)
        {
          l=15-i;
        lcd.print(c[l]);
        delay(90);
        }
        lcd.setCursor(0,0);
        lcd.clear();
        lcd.print("ARRV Manipulator");
          k--;
        }
      }
      intro = false;
      lcd.clear();
      servo.write(0);
}
