//if return 1 use this: sudo chmod 666 /dev/ttyACM0

int ledpin=2;
boolean serialOn=false;
boolean active=true;
int led=1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  serialOn=true;
Serial.println("hi");

}

void loop() {
  // put your main code here, to run repeatedly:

Serial.println(analogRead(A1));
delay(750);

if(analogRead(A1)==1023 && serialOn)
{
  Serial.println("1023 reaced, ending connection");
  Serial.end();
  serialOn=false;
  delay(750);
  Serial.begin(9600);

}

else if(analogRead(A1)==1023 && !serialOn)
  {serialOn=true;
  Serial.println("please stop being at max");
  active=false;}

  if(analogRead(A1)!=1023 && !active)
  {Serial.println("Thank You");
  active=true;}


if(led=1){
  if(active && analogRead(A2)!=1023)
  ledb(2);

  if(active)
  ledconst(2);}

else if(led=2){
  if(active && analogRead(A2)!=1023)
  ledb(4);

  if(active)
  ledconst(4);}
        
else if(led=3){
if(active && analogRead(A2)!=1023)
  ledb(2);

  if(active)
  ledconst(2);}

  if(active && analogRead(A2)!=1023)
  ledb(4);

  if(active)
  ledconst(4);
     
}
}
  

  if(active)
  ledswitch();

  //String com=Serial.readString();
  //coms(com);

}

void ledb(int x)
{

  pinMode(x, HIGH);
  delay(750);
  pinMode(x,LOW);

}

void ledconst(int x)
{

  if(analogRead(A2)==1023)
  {
    pinMode(x, HIGH);
    Serial.println("!!Constant power!!");
  }

}

void ledswitch(){

if(analogRead(A0)==1023 && led==1)
{led=2;
    Serial.println("hdhhdhdhdhdhdjsjs");}

else if(analogRead(A0)==1023 && led==2)
led=1;
    
else if (analogRead(A4)==1023)
led=3;

}

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
