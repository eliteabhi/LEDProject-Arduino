//if return 1 use this: sudo chmod 666 /dev/ttyACM0

//constants
int ledpin=2;
boolean serialOn=false;
boolean active=true;
int led=1;
int cont=0;
  //////////////////////

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  serialOn=true;
Serial.println("hi");

}
    ////////////////////////

void loop() {
  // put your main code here, to run repeatedly:

    //prints state if A1 every 750ms
Serial.println(analogRead(A1));
delay(750);

    //prints A1 hitting max(1023) w/serial on
if(analogRead(A1)==1023 && serialOn)
{
  Serial.println("1023 reaced, ending connection");
  Serial.end();
  serialOn=false;
  delay(750);
  Serial.begin(9600);

}
        //////////////////////
    
    //tells A1 max(1023) hit w/ serial off
else if(analogRead(A1)==1023 && !serialOn)
  {serialOn=true;
  Serial.println("please stop being at max");
  active=false;}

  if(analogRead(A1)!=1023 && !active)
  {Serial.println("Thank You");
  active=true;}
     /////////////////////
    
//led-1 controls
if(led=1){
  if(active && analogRead(A2)!=1023)
  ledb(2);

  if(active)
  ledconst(2);}
    /////////////////////

    //led-2 controls
else if(led=2){
  if(active && analogRead(A2)!=1023)
  ledb(4);

  if(active)
  ledconst(4);}
        ///////////////////
    
    //both led-1 & led-2 controls
else if(led=3){
if(active && analogRead(A2)!=1023)
  ledb(2);

  if(active)
  ledconst(2);

  if(active && analogRead(A2)!=1023)
  ledb(4);

  if(active)
  ledconst(4);
     ////////////////////
    
}

    //auto switching betweeen two leds
else if(led==4 && active){
        
  if(cont<30000)
{autoswitch(2);
 delay(1);
 cont++;
}
        
   if(cont>30000 && cont<60000)
     {
            autoswitch(4);
            delay(1);
            cont++;
        }
   if(cont==30000)
    {
            cont=1;
            autoswitch(2);
        }
}
    //////////////////////////

//switch between 1,2,3
  if(active)
  ledswitch();

  //String com=Serial.readString();
  //coms(com);

}
     ///////////////////////////


//blinks #x led/leds (default)
void ledb(int x)
{

  pinMode(x, HIGH);
  delay(750);
  pinMode(x,LOW);

}
     //////////////////////

//keeps #x led/leds constant with pin A2
void ledconst(int x)
{

  if(analogRead(A2)==1023)
  {
    pinMode(x, HIGH);
    Serial.println("!!Constant power!!");
  }

    ////////////////////////
    
}

//switches led/leds with pin A0
void ledswitch(){

if(analogRead(A0)==1023 && led==1)
{led=2;
    Serial.println("hdhhdhdhdhdhdjsjs");}

else if(analogRead(A0)==1023 && led==2)
led=1;
    
else if (analogRead(A4)==1023)
led=3;
    
else if(analogRead(A5)==1023)
led=4;

}
       ////////////////////////

//automatically switches between leds
void autoswitch(x){
    
    if(analogRead(A5)==1023)
    {   ledb(x);
        ledconst();}
    
}
       //////////////////////////

void coms(String com)
{

if (com.equals("stop"))
    {
      active=false;
      Serial.println("!!blink stopped!!");
    }

if(com.equals("start"))
{
  active=true;
  Serial.println("!!blink started!!");
}

if(com.equals("kill"))
{
  Serial.println("!!Program killed!!");
  Serial.end();
}

}
