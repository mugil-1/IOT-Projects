#include <WiFi.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <ThingSpeak.h>
char ssid[] = "Wokwi-GUEST";
char pass[] = "";
WiFiClient client;
Adafruit_MPU6050 m_p_u;
long myChannelNumber = 2685891;
const char * myWriteAPIKey = "VW3VO797O11OQ4FT";
int statusCode;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  while(!Serial)
  delay(20);
  if(!m_p_u.begin()){
  while(1){
      delay(20);
       
    }
  }
  ThingSpeak.begin(client);
}

void loop() {

  if(WiFi.status() != WL_CONNECTED)  
  {
  Serial.print("Attempting to connect");
    while(WiFi.status() != WL_CONNECTED)
    {
    WiFi.begin(ssid, pass); 
    Serial.print(".");
    delay(5000);
    }
  Serial.println("\nConnected.");
  }
  
sensors_event_t acc, gcc, temp;
m_p_u.getEvent(&acc, &gcc, &temp);

Serial.println("Rotation of x axis: ");
int x_axis=(gcc.gyro.x)*180/3.14;
Serial.println(x_axis);
  delay(1000);


Serial.println("Rotation of y axis: ");
int y_axis=(gcc.gyro.y)*180/3.14;
Serial.println(y_axis);
  delay(1000);


Serial.println("Rotation of z axis: ");
int z_axis=(gcc.gyro.z)*180/3.14;
Serial.println(z_axis);
  delay(1000);


if(x_axis >=-5 && x_axis <=5){
  Serial.println("horizontally safe");
}
else if ((x_axis >=-15 && x_axis <=-6)||(x_axis >=6 && x_axis <=15)){
  Serial.println("horizontally unsafe");
}
else {
  Serial.println("horizontally danger");
}
if (y_axis >=-5 && y_axis <=5) {
  Serial.println("vertically safe");
}
else if ((y_axis >=-15 && y_axis <=-6)||(y_axis >=6 && y_axis <=15)){
  Serial.println("vertically unsafe");
}
else{
  Serial.println("vertically danger");
}
if (z_axis >=-5 && z_axis <=5){
    Serial.println("forward & backward safe");
   }
else if ((z_axis >=-15 && z_axis <=-6)||(z_axis >=6 && z_axis <=15)){
  Serial.println("forwad & backward unsafe");
}
else{
  Serial.println("forward & backward danger");
}
   
                 
 
delay(3000);

 ThingSpeak.setField(1,x_axis);
   ThingSpeak.setField(2,y_axis);
    ThingSpeak.setField(3,z_axis);

  statusCode = ThingSpeak.writeFields(myChannelNumber,myWriteAPIKey);

if(statusCode == 200) { //successful writing code
Serial.println("Channel update successful.");
}
else {
Serial.println("Problem Writing data. HTTP error code :" +
String(statusCode));
}

}
