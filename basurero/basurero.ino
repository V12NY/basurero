short mtr1=5;
short mtr2=6;
short trig=12;
short echo=13;
short led=1;

int pulso=150;
int distance=0;
int aux=0;
unsigned long ctrlTiempo=0;
int tiempo=0;
void setup() {
  attachInterrupt(digitalPinToInterrupt(2),knowTime,RISING);//interup pin 2 en nflanco de subida
  pinMode(mtr1,OUTPUT);
  pinMode(mtr2,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(led,OUTPUT);
  
}

void loop() {
  analogWrite(mtr1,pulso);
  analogWrite(mtr2,pulso);
  
  if(tiempo!=0){
    ctrlTiempo=millis();
    if(millis()-ctrlTiempo==tiempo*1/4){
      analogWrite(mtr2,pulso*1.5);
    }
    if(millis()-ctrlTiempo==tiempo*3/4){
      analogWrite(mtr1,pulso*1.5);
    }
  }

}
void knowTime(){
  distance=distancia();
  ctrlTiempo=millis();
  while(distance!=aux){
    aux=distancia();
  }
  tiempo=millis()-ctrlTiempo;
  digitalWrite(led,HIGH);
}
int distancia(){
  long duracion;
  digitalWrite(trig,LOW);
  delayMicroseconds(4);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duracion =pulseIn(echo,HIGH)/58;
  return duracion;
}

