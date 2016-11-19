/*
  AT+ROLE0 >> THE MOUDULE SHOULD BE IN PERI MODE TO BE ABLE TO CONNECT WITH PHONE
  AT+MODE0 >>
  AT+NAME >> ADD NAME TO THE BLE
  AT+SHOW >> 0 TO HIDE NAME, 1 TO SHOW NAME
  AT+VERR? >> GET VERISON INFO, THE ONE YOU HAVE IS "540"
  AT+NOTI  >> 0/1 If this value is set to 1, when link ESTABLISHED or LOSTED module will send OK+CONN or OK+LOST string through UART. //SET IT TO 1
*/

String output;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial1.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("hi");
  // set the data rate for the SoftwareSerial port
  // set master
  //  Serial1.print("AT+RENEW");
  //  delay(300);
  //  Serial1.print("AT+ROLE0");
  //  delay(300);
  //  Serial1.print("AT+MODE0");
  //  delay(300);
  //  Serial1.print("AT+NAMEFRASEN");
  //  delay(300);
  //  Serial1.print("AT+SHOW1");
  //  delay(300);
  //  Serial1.print("AT+NOTI1");
  //  delay(500);
  delay(1000);
}
void loop() // run over and over
{

  // set the data rate for the SoftwareSerial port
  if (Serial1.available()) {
  output = Serial1.readString();
  Serial.print(output);
  }
  if (Serial.available())
    Serial1.write(Serial.read());
    Serial.println("");

    while (output.equals("OK+CONN")) {
      Serial.println("BLE connected");
      Serial1.write("12345678901234567890");
      delay(30);
    }
}
