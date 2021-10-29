// ---------------------------------------------------------------- //
// MikroKendali.com
// Menggunakan Arduino IDE 1.8.8
// Menggunakan Sensor LDR dan Resistor 10K
// Telah Teruji pada tanggal 1 Juli 2021
// ---------------------------------------------------------------- //
#define LDR A2 // Pin LDR di Analog 2
#define LAMPU 5 // pin LED di D5
int nilai; // variabel nilai sebagai penyimpan nilai analog LDR
void setup() {
  pinMode(LDR,INPUT); // LDR sebagai Input
  pinMode(LAMPU,OUTPUT); // LAMPU sebagai OUTPUT
  Serial.begin(9600); //Nilai baudrate serial monitor
}
void loop() {
  nilai = analogRead(LDR); // membaca nilai LDR
  Serial.print("Nilai = "); 
  Serial.print(nilai); //menampilkan nilai LDR
  Serial.print("  "); // sebagai spasi saja
 
  //mengetahui terang dan redup cahaya, jika Nilai LDR lebih 500 maka terang jika tidak maka redup
  if(nilai > 500 ){
    Serial.println("Terang"); // ditambah PrintLN sebagai Spasi bawah 
  }else{
    Serial.println("Redup"); // ditambah PrintLN sebagai Spasi bawah 
  }

  delay(500); // jeda setiap 1/2 detik supaya serial monitor tidak terlalu cepat membaca

  //opsional
  //jika cahaya luar terang maka lampu OFF, jika cahaya luar Gelap maka Lampu ON
  if( nilai > 250 ){
    digitalWrite(LAMPU,LOW);
  }else{
    digitalWrite(LAMPU,HIGH);
  }
}
