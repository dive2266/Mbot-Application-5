#include <MeMCore.h>
float board = 0;
float module = 0;
float tem=0;
float pir=0;
int abc = 0 ;
MeRGBLed rgbled_7(7,2);
MeRGBLed rgbled_1(4,4);
int bright=0;
MePIRMotionSensor pir_1(1);
MeTemperature temperature_3_1(2, 1);
MeLightSensor lightsensor_6(6);
MeLightSensor lightsensor_3(3);
MeDCMotor motor_9(9);
MeDCMotor motor_10(10);
double Offset_9_motor=0;
double Offset_10_motor=0;
void setup() {
Serial.begin(9600);
}
void loop() {
board = lightsensor_6.read();
module = lightsensor_3.read();
Serial.print(board);
Serial.print("**********");
Serial.println(module);
if(board <500){
motor_9.run(-(100));
motor_10.run((100));}
 else if (module<550){
motor_9.run(100);
motor_10.run(-100);}
 else {
motor_9.run(0);
motor_10.run(0);/*光源拉力*/
tem=temperature_3_1.temperature();
Serial.println(tem);
delay(200);/*溫度*/
if(tem>30)
{ 
  rgbled_7.setColor(0,150,150,150);
  rgbled_7.show();
  }
else
{
   rgbled_7.setColor(0,0,0,0);
  rgbled_7.show();
 }
 sensor();
}
}
void light(){
for(int i =4;i>0;i--){
  if(bright<=255){
rgbled_1.setColor(0,0,0,0);
rgbled_1.show();
rgbled_1.setColor(i,bright,0,0);
rgbled_1.show();
delay(500);
bright+=5;
}
else{
  bright=0;
  rgbled_1.setColor(0,0,0,0);
  rgbled_1.show();
}
}
}
void light2(){
for(int i =4;i>0;i--){
  if(bright<=255){
rgbled_1.setColor(0,0,0,0);
rgbled_1.show();
rgbled_1.setColor(i,0,bright,0);
rgbled_1.show();
delay(500);
bright+=5;
}
else{
  bright=0;
  rgbled_1.setColor(0,0,0,0);
  rgbled_1.show();
}
}
}
void light3(){
for(int i =4;i>0;i--){
  if(bright<=255){
rgbled_1.setColor(0,0,0,0);
rgbled_1.show();
rgbled_1.setColor(i,0,0,bright);
rgbled_1.show();
delay(500);
bright+=5;
}
else{
  bright=0;
  rgbled_1.setColor(0,0,0,0);
  rgbled_1.show();
}
}
}
void sensor(){
pir=pir_1.isHumanDetected();
Serial.println(pir);
if(pir==1){
abc +=1;
}
delay(500);/*人體紅外線*/
switch ((int)abc){
case 1 :
light();
break;
case 2 :
light2();
break;
case 3:
light3();
break;
default:
abc = 0;
}
}
