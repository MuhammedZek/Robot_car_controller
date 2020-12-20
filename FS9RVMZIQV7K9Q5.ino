int izqA = 9; 
int izqB = 10; 
int derA = 11; 
int derB = 12; 
int vel = 255; // Velocidad de los motores (0-255)
int estado = 0; // inicia detenido

void setup() { 
Serial.begin(9600); // inicia el puerto serial para comunicacion con el Bluetooth
pinMode(derA, OUTPUT);
pinMode(derB, OUTPUT);
pinMode(izqA, OUTPUT);
pinMode(izqB, OUTPUT);
} 

void loop() { 

if(Serial.available()>0){ // lee el bluetooth y almacena en estado
estado = Serial.read();
}
if(estado=='1'){ // Forward
  Serial.println(estado);
analogWrite(derB, 0); 
analogWrite(izqB, 0); 
analogWrite(derA, vel); 
analogWrite(izqA, vel); 
}
if(estado=='2'){ // right
    Serial.println(estado);
analogWrite(derB, 0); 
analogWrite(izqB, 0); 
analogWrite(derA, 100); 
analogWrite(izqA, 200); 
}
if(estado=='3'){ // Stop
    Serial.println(estado);
analogWrite(derB, 0); 
analogWrite(izqB, 0); 
analogWrite(derA, 0); 
analogWrite(izqA, 0); 
}
if(estado=='4'){ // left
    Serial.println(estado);
analogWrite(derB, 0); 
analogWrite(izqB, 0);
analogWrite(izqA, 100);
analogWrite(derA, 200); 
} 

if(estado=='5'){ // Reverse
    Serial.println(estado);
analogWrite(derA, 0); 
analogWrite(izqA, 0);
analogWrite(derB, vel); 
analogWrite(izqB, vel); 
}
if(estado=='6'){ // left
    Serial.println(estado);
analogWrite(derB, 0); 
analogWrite(izqB, vel);
analogWrite(izqA, 0);
analogWrite(derA, vel); 
} 

}
