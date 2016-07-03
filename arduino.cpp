#include <AFMotor.h>
#include <Ultrasonic.h>

int trigPin(24);//<- seta a porta do arduino, no caso uma analogica do arduino mega
int echoPin(22);

AF_DCMotor motor1(1);//o "motor1" é uma variavel e o número de parâmetro o motor correspondente no motor shield
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup()
{
	Serial.begin(9600);
  pinMode (trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  int velocidade = 130;
  int cont = 1;
   int a = Serial.read();

if(a != -1){

		if(a == 'w') {

			Serial.println("Indo para frente");
			motor1.setSpeed(velocidade);
			motor1.run(FORWARD);
			motor2.setSpeed(velocidade);
			motor2.run(FORWARD);
			motor3.setSpeed(velocidade); 
			motor3.run(FORWARD);
			motor4.setSpeed(velocidade);
			motor4.run(FORWARD);

			long duration, distance;
			digitalWrite (trigPin, LOW);
			delayMicroseconds(2);
			digitalWrite (trigPin, HIGH);
			delayMicroseconds (10);
			digitalWrite(trigPin, LOW);
			duration = pulseIn (echoPin, HIGH);
			distance = (duration/2) / 29.1;

				while(cont == 1){

					digitalWrite (trigPin, LOW);
					delayMicroseconds(2);
					digitalWrite (trigPin, HIGH);
					delayMicroseconds (10);
					digitalWrite(trigPin, LOW);
					duration = pulseIn (echoPin, HIGH);
					distance = (duration/2) / 29.1;
    				if((a == 's') || (a == 'q') || (a == 'd') || (a == 'a')){ cont = 2;}
    				if(distance <30){

								motor1.setSpeed(0);
								motor2.setSpeed(0);
								motor3.setSpeed(0);
								motor4.setSpeed(0);

								motor1.run(RELEASE);
								motor2.run(RELEASE);
								motor3.run(RELEASE);
								motor4.run(RELEASE);
						}
            else{
              	motor1.setSpeed(velocidade);
								motor2.setSpeed(velocidade);
								motor3.setSpeed(velocidade);
								motor4.setSpeed(velocidade);

								motor1.run(FORWARD);
								motor2.run(FORWARD);
								motor3.run(FORWARD);
								motor4.run(FORWARD);

            }
		  }
	}


  if(a == 's') {

			Serial.println("Indo para trás");//desliga os motores

			motor1.setSpeed(velocidade); //liga os motores
			motor1.run(BACKWARD);
			motor2.setSpeed(velocidade);
			motor2.run(BACKWARD);
			motor3.setSpeed(velocidade); //liga os motores
			motor3.run(BACKWARD);
			motor4.setSpeed(velocidade);
			motor4.run(BACKWARD);
}


	if(a == 'd'){

			Serial.println("Girando para direita");
			motor1.setSpeed(150);
			motor1.run(FORWARD);
			motor2.setSpeed(150);
			motor2.run(FORWARD);
			motor3.setSpeed(150);
			motor3.run(BACKWARD);
			motor4.setSpeed(150);
			motor4.run(BACKWARD) ;

			delay(500);

			motor1.run(RELEASE);
			motor2.run(RELEASE);
			motor3.run(RELEASE);
			motor4.run(RELEASE);
 }

	if(a == 'a'){
			Serial.println("Girando para esquerda");

			motor1.setSpeed(150);
			motor1.run(BACKWARD);
			motor2.setSpeed(150);
			motor2.run(BACKWARD);
			motor3.setSpeed(150);
			motor3.run(FORWARD);
			motor4.setSpeed(150);
			motor4.run(FORWARD) ;

			delay(500);

			motor1.run(RELEASE);
			motor2.run(RELEASE);
			motor3.run(RELEASE);
			motor4.run(RELEASE);
 }

	if(a == 'q'){
			Serial.println("parando");

			motor1.setSpeed(0);
			motor2.setSpeed(0);
			motor3.setSpeed(0);
			motor4.setSpeed(0);
			motor1.run(RELEASE);
			motor2.run(RELEASE);
			motor3.run(RELEASE);
			motor4.run(RELEASE);
	}
 }
}
