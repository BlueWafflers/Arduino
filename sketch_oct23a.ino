int pinA = 12;
int pinB = 13;
int pinC = 11;
int pinD = 8;
int switch1=6;
int switch2=2;
int switch3=5;
int switch4=4;
int switch5=3;

boolean shouldChange = false;
boolean done1=false;
boolean done2=false;
boolean done3=false;
boolean done4=false;
boolean done5=false;

int incomingByte = 0;
  byte command[7];

  
  int counter = 0;
  
int vcc=0;
int indoorSensor=A1;
int attcSensor=A2;
int outdoorSensor=9;
float temp;
float tempc;


void setup() {
  // put your setup code here, to run once:
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(switch1,INPUT);
  pinMode(switch2,INPUT);
   pinMode(switch3,INPUT);
  pinMode(switch4,INPUT);
pinMode(switch5,INPUT); 
pinMode(vcc,INPUT);
pinMode(indoorSensor,INPUT);
pinMode(attcSensor,INPUT);
 pinMode(outdoorSensor,INPUT); 

Serial.begin(9600);
}

void changeMux(int a, int b, int c, int d){
  digitalWrite(pinA, (a == 1 ? HIGH : LOW));
  digitalWrite(pinB, (b == 1 ? HIGH : LOW));
  digitalWrite(pinC, (c == 1 ? HIGH : LOW));
  digitalWrite(pinD, (d == 1 ? HIGH : LOW));
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
   Serial.readBytes(command,7);
   Serial.write(command,7);
  } 


// Check Command
  if (command[0] == 'D'){   
    // Indoor Lighting
    if (command[1]==1){
      if (command[4] == 'T'){
        // INDOOR LIGHT ON
          changeMux(0, 0, 1, 0);       
      } else if (command[4] == 'F') {
        // INDOOR LIGHt OFF
          changeMux(1, 0, 1, 0);
      }
    }
    // Outdoor Lighting
    if (command[1] == 2){
      if (command[4] == 'T'){
        // OUTDOOR LIGHt ON
        changeMux(0, 1, 1, 1);
      } else if (command[4] == 'F'){
        // OUTDOOR LIGHT OFF
        changeMux(1, 1, 1, 1);
      }

      
        }
        // Sound alarm part
   if (command[1] == 3){
      if (command[4] == 'T'){
        // Alarm ON
        changeMux(1, 0, 0, 0);
      } else if (command[4] == 'F'){
        // Alarm OFF
        changeMux(0, 0, 0, 0);
      }
        }
        //Timer2 part
       if (command[1] == 4){
      if (command[4] == 'T'){
        // ON
        changeMux(0, 0, 0, 1);
      } else if (command[4] == 'F'){
        // OFF
        changeMux(1, 0, 0, 1);
      }
        }
        //Heating element wind
       if (command[1] == 5){
      if (command[4] == 'T'){
        //  ON
        changeMux(0, 1, 1, 0);
      } else if (command[4] == 'F'){
        // OFF
        changeMux(1, 1, 1, 0);
      }
        }
        //Timer1
 if (command[1] == 6){
      if (command[4] == 'T'){
        // ON
        changeMux(0, 1, 0, 0);
      } else if (command[4] == 'F'){
        // OFF
        changeMux(1, 1, 0, 0);
      }
        }
        //Heating element 
   if (command[1] == 7){
      if (command[4] == 'T'){
        //  ON
        changeMux(0, 1, 0, 1);
      } else if (command[4] == 'F'){
        //  OFF
        changeMux(1, 1, 0, 1);
      }
        }  
        //Indication burglar alarm lamp
     if (command[1] == 8){
      if (command[4] == 'T'){
        // OUTDOOR LIGHt ON
        changeMux(0, 0, 1, 1);
      } else if (command[4] == 'F'){
        // OUTDOOR LIGHT OFF
        changeMux(1, 0, 1, 1);
      }
     }  
        //indoor temp no.9
        if(command[1]==9){
          
  temp=analogRead(indoorSensor); // 读取LM35的输出
  tempc=temp*0.48828125;       // 将输出数值转换为摄氏度
  
  //Serial.println("...............");
Serial.print('D');
Serial.print(9);
Serial.print('C');
Serial.print(1);
Serial.print('S');
Serial.print(tempc);
Serial.print('E');
 
  
  
        }
 // Temp Attc  No.10
if(command[1]==10){
  
  temp=analogRead(attcSensor); // 读取LM35的输出
  tempc=temp*0.48828125;       // 将输出数值转换为摄氏度
  
  //Serial.println("...............");
  
Serial.print('D');
Serial.print(10);
Serial.print('C');
Serial.print(1);
Serial.print('S');
Serial.print(tempc);
Serial.print('E');
  
}
//Temp outDoor N.11

if (command[1]==11){
  
temp=digitalRead(outdoorSensor); 
Serial.print('D');
Serial.print(11);
Serial.print('C');
Serial.print(1);
Serial.print('S');
Serial.print(temp);
Serial.print('E');
  
}} 
//Window Switch N.12

 if(digitalRead(switch1)==HIGH && !done1){
  Serial.print('S');
Serial.print(12);
Serial.print('T');
Serial.print('E');
Serial.print('E');
Serial.print('E');
Serial.print('E');
  done1=true;
  }
  
 if (digitalRead(switch1) == LOW && done1){
  Serial.print('S');
Serial.print(12);
Serial.print('F');
Serial.print('E');
Serial.print('E');
Serial.print('E');
Serial.print('E');
  done1 = false;
 }
 
  //Fire switch N.13
if(digitalRead(switch2)==HIGH && done2==false){
Serial.print('S');
Serial.print(13);
Serial.print('T');
Serial.print('E');
Serial.print('E');
Serial.print('E');
Serial.print('E');
  done2=true;
  }
 if (digitalRead(switch2) == LOW && done2==true){
  Serial.print('S');
Serial.print(13);
Serial.print('F');
Serial.print('E');
Serial.print('E');
Serial.print('E');
Serial.print('E');
  done2 = false;
 }else{

  }


//Oven switch N.14
if(digitalRead(switch3)==HIGH && done3==false){
Serial.print('S');
Serial.print(14);
Serial.print('T');
Serial.print('E');
Serial.print('E');
Serial.print('E');
Serial.print('E');
  done3=true;
  }else{
 
 }
 if (digitalRead(switch3) == LOW && done3==true){
  Serial.print('S');
Serial.print(14);
Serial.print('F');
Serial.print('E');
Serial.print('E');
Serial.print('E');
Serial.print('E');
  
  done3 = false;
 }else{

  }
//Water Leakage Switch.15
if(digitalRead(switch4)==HIGH && done4==false){
Serial.print('S');
Serial.print(15);
Serial.print('T');
Serial.print('E');
Serial.print('E');
Serial.print('E');
Serial.print('E');
  done4=true;
  }else{

 }
 if (digitalRead(switch4) == LOW && done4==true){
  Serial.print('S');
Serial.print(15);
Serial.print('F');
Serial.print('E');
Serial.print('E');
Serial.print('E');
Serial.print('E');
  done4 = false;
 }else{

  }
//Door Switch N.16
if(digitalRead(switch5)==LOW && done5==false){
Serial.print('S');
Serial.print(16);
Serial.print('T');
Serial.print('E');
Serial.print('E');
Serial.print('E');
Serial.print('E');
  done5=true;
  }else{

 }
 if (digitalRead(switch5) == HIGH && done5==true){
  Serial.print('S');
Serial.print(16);
Serial.print('F');
Serial.print('E');
Serial.print('E');
Serial.print('E');
Serial.print('E');
  done5 = false;
 }else{

  }

delay(500);


    
   
   for( int i=0;i<7;i++){
    command[i]=0;
   }
  }
   


  
