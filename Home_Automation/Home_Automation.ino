
#define RELAY1  7
#define RELAY2  5


int tx=1;
int rx=0;
int inSerial;


void setup(){
Serial.begin(9600);

pinMode(RELAY1, OUTPUT);
pinMode (RELAY2, OUTPUT);
  
pinMode(tx, OUTPUT);
pinMode(rx, INPUT);
allpinslow();
}

void loop(){

//delay(200);
if (Serial.available() > 0) {
inSerial=Serial.read();
}

if (inSerial ==1 || inSerial== 2) {
   Check_Protocol1(inSerial); 
}

if (inSerial ==3 || inSerial== 4) {
   Check_Protocol2(inSerial); 
}
}


void allpinslow()
{
digitalWrite(RELAY1, HIGH);
digitalWrite(RELAY2, HIGH);
}


void Check_Protocol1(int inStr){

Serial.println(inStr);


if(inStr == 1){ //Led Off
digitalWrite(RELAY1, 1);
Serial.println("RELAY1 OFF");
}


else if(inStr == 2){ //Led on
digitalWrite(RELAY1, 0);
Serial.println("RELAY1 ON");
}

}




void Check_Protocol2(int inStr){

Serial.println(inStr);

if(inStr == 3){ //Led Off
digitalWrite(RELAY2, 1);
Serial.println("RELAY2 0FF");
}


else if(inStr == 4){ //Led on
digitalWrite(RELAY2, 0);
Serial.println("RELAY2 0N");
}
}
