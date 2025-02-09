
HardwareSerial bt(PA10, PA9);
  const int pinout = PB10; // declare pinout with int data type and pin value
  char t = 0;  //Variable for storing received data
  const int sprinkle = PB5;
  const int sprinkle_out =PB6;
  const int motorA1  = PA0;  //10
  const int motorA2  = PA1;  //9
  const int motorB1  = PA2;  //8
  const int motorB2  = PA3; //7
  
void setup()
{
    bt.begin(9600);                      //Sets the baud rate for bluetooth pins                      
    pinMode(pinout, OUTPUT);  
    pinMode(motorA1,OUTPUT);   //left motors  forward
    pinMode(motorA2,OUTPUT);   //left motors reverse
    pinMode(motorB1,OUTPUT);   //right  motors forward
    pinMode(motorB2,OUTPUT);                 //Sets digital pin PA0 as output pin for led
}

void loop()
{
   if(bt.available() > 0)      // Send data only when you receive data:
   {
      t = bt.read();        //Read the incoming data & store into data
           
      if(t == 'W') 
      {
         digitalWrite(pinout, HIGH); 
         bt.print("LED ON\n");
      }
         
      else if(t == 'w')  
      {      
         digitalWrite(pinout, LOW);  
         bt.print("LED OFF\n");  
      }

       if(t == 'X') 
       {
          digitalWrite(sprinkle, HIGH); 
          digitalWrite(sprinkle_out, LOW); 
         bt.print("Sprinkle on\n");
       }
         
       else if(t == 'x')  
       {      
          digitalWrite(sprinkle, LOW);  
          digitalWrite(sprinkle_out, LOW);
          bt.print("sprinkle off\n");  
       }
      
if(t == 'F'){            //move  forward(all motors rotate in forward direction)
  digitalWrite(motorA1,HIGH);
  digitalWrite(motorB1,HIGH);
  bt.println("FORWARD");
}
 
else if(t == 'B'){      //move reverse (all  motors rotate in reverse direction)
  digitalWrite(motorA2,HIGH);
  digitalWrite(motorB2,HIGH);
  bt.println("BACK");
}
  
else if(t == 'L'){      //turn right (left side motors rotate in forward direction,  right side motors doesn't rotate)
  digitalWrite(motorB1,HIGH);
  bt.println("LEFT");
}
 
else  if(t == 'R'){      //turn left (right side motors rotate in forward direction, left  side motors doesn't rotate)
  digitalWrite(motorA1,HIGH);
  bt.println("RIGHT");
}

else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite( motorA1,LOW);
  digitalWrite(motorA2,LOW);
  digitalWrite(motorB1,LOW);
  digitalWrite(motorB2,LOW);
  bt.println("STOP");
}

   }
   delay(100);
}