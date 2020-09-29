// Define pins for ultrasonic and buzzer
#define relay 10
int LED = 12;
int LDR = A0;
int const trigPin = 10;
int const echoPin = 9;
int const buzzPin = 2;
int ulltrigg=4;
int ullecho=6;

void setup()
{
  pinMode(trigPin, OUTPUT); // trig pin will have pulses output
  pinMode(echoPin, INPUT); // echo pin should be input to get pulse width

pinMode(ulltrigg,OUTPUT);//as output is to trigger beam
  //configuring pin as output.
//outputs: low impedence state, current to rest of the circuit
  pinMode(ullecho, INPUT);//as Input is to recieve the reflected beam.
  pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzering
    
  Serial.begin(9600);
pinMode(LED, OUTPUT);
pinMode(relay, OUTPUT);
pinMode(LDR, INPUT);
}

void loop()
{
  // Duration will be the input pulse width and distance will be the distance to the obstacle in centimeters
  int duration, distance,dist,dur;
  // Output pulse with 1ms width on trigPin
  digitalWrite(trigPin, HIGH); 
  delay(1);
  digitalWrite(trigPin, LOW);
  // Measure the pulse input in echo pin
  duration = pulseIn(echoPin, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance = (duration/2) / 29.1;
  digitalWrite(ulltrigg, HIGH); 
  delay(1);
  digitalWrite(ulltrigg, LOW);
  dur=pulseIn(ullecho,HIGH);
  dist= (dur/2)/29.1;
  // if distance less than 0.5 meter and more than 0 (0 or less means over range) 
    if (distance <= 10 && distance >= 0 && dist<=10 && dist >0) {
      // Buzz
      digitalWrite(buzzPin, LOW);
    } else if(distance <=15 && distance>0 && dist>=10) {
      // Don't buzz
      digitalWrite(buzzPin,HIGH);
      delay(300);
      digitalWrite(buzzPin,LOW);
    }
    // Waiting 60 ms won't hurt any one
    delay(60);
int LDRValue = analogRead(LDR);
Serial.print("sensor = ");
Serial.print(LDRValue);

if (LDRValue <=900) 
{
digitalWrite(LED, HIGH);
digitalWrite(relay, HIGH);
Serial.println("It's Dark Outside; Lights status: ON");
}
else 
{
digitalWrite(LED, LOW);
digitalWrite(relay, LOW);
Serial.println("It's Bright Outside; Lights status: OFF");
}
delay(60);
}
