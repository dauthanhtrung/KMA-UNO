/*
     _             _   _                 _     _
  __| | __ _ _   _| |_| |__   __ _ _ __ | |__ | |_ _ __ _   _ _ __   __ _
 / _` |/ _` | | | | __| '_ \ / _` | '_ \| '_ \| __| '__| | | | '_ \ / _` |
| (_| | (_| | |_| | |_| | | | (_| | | | | | | | |_| |  | |_| | | | | (_| |
 \__,_|\__,_|\__,_|\__|_| |_|\__,_|_| |_|_| |_|\__|_|   \__,_|_| |_|\__, |
                                                                    |___/
*/
//*****************************************************************//
// Copyright by Dau Thanh Trung
// Project: Example Code for Arduino UNO Limited Version KMA
// Date:    1/11/2024
// Author:  Dau Thanh Trung
// Phone:   0868.24.25.09
// Mail:    dauthanhtrung.kma@gmail.com
// Site:    www.facebook.com/dauthanhtrung.kma
// Git:     www.github.com/dauthanhtrung
//*****************************************************************//
//Khai báo các chân kết nối
//Cần phải gạt 2 công tắc bit ở trên KMA-UNO để led và còi hoạt động
#define BUTTON 2                           // Kết nối nút nhấn với pin 2 (hỗ trợ ngắt interrupt 2)
#define BUZZER 13                          // Kết nối với còi chip với pin 13
byte LED[] = { 3, 4, 5, 6, 7, 8, 9, 10 };  // Kết nối với LED từ pin 3 - pin 10

#define ON 1                   // ~HIGH Bật
#define OFF 0                  // ~LOW  Tắt
int time_delay = 100;          // Biến lưu thời gian delay của hiệu ứng
unsigned int MODE;             // Biến mode để lưu chương trình đang chạy theo chế độ
void CheckButtonInterrupt() {  //Chương trình ngắt
  MODE++;                      //Chuyển đổi giữa các chế độ dùng ngắt
  if (MODE > 10) MODE = 0;     //có 10 chương trình nháy led
}
void bip(uint16_t time_delay) {  //còi chip kêu theo thời gian được set
  digitalWrite(BUZZER, ON);
  delay(time_delay);
  digitalWrite(BUZZER, OFF);
  delay(time_delay);
}
void setup() {
  //Khởi tạo GPIO input, output
  for (int i = 0; i < 8; i++) {
    pinMode(LED[i], OUTPUT);    //Khởi tạo LED là OUTPUT
    digitalWrite(LED[i], OFF);  // Tắt các đèn
  }

  pinMode(BUZZER, OUTPUT);                            //Khởi tạo còi chip là OUTPUT
  pinMode(BUTTON, INPUT_PULLUP);                      //Khởi tạo nút nhấn với trở treo lên VCC
  attachInterrupt(0, CheckButtonInterrupt, FALLING);  //Khởi tạo ngắt ở pin 2
  MODE = 10;                                          //gọi chế độ mặc định là 10
  bip(100);                                           //còi chip kêu
  bip(100);
  // bip(200);
  // Khởi tạo thành công!
}

void loop() {  //Chương trình chính
  //Chọn chế độ để hoạt động theo chương trình con
  // if (!MODE) bip(200);
  switch (MODE) {
    case 0:
      MODE0();
      break;
    case 1:
      MODE1();
      break;
    case 2:
      MODE2();
      break;
    case 3:
      MODE3();
      break;
    case 4:
      MODE4();
      break;
    case 5:
      MODE5();
      break;
    case 6:
      MODE6();
      break;
    case 7:
      MODE7();
      break;
    case 8:
      MODE8();
      break;
    case 9:
      MODE9();
      break;
    case 10:
      MODE10();
      break;
  }
}
//************************Chương trình con******************************//
void All_OFF() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], OFF);  // tắt cả 8 led
  }
}
void All_ON() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], ON);  // bật cả 8 led
  }
}
void MODE0() {  //Chế độ 0: nhấp nháy led
  //int time_delay = 100;
  All_ON();
  delay(time_delay);
  All_OFF();
  delay(time_delay);
}
void MODE1() {  //Chế độ 1: sáng dồn từ dưới lên
  //int time_delay = 100;
  All_OFF();
  delay(time_delay);
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], ON);  // sáng dần
    delay(time_delay);
  }
}
void MODE2() {  //Chế độ 2: sáng dồn từ trên xuống
  //int time_delay = 100;
  All_OFF();
  delay(time_delay);
  for (int i = 7; i >= 0; i--) {
    digitalWrite(LED[i], ON);  // sáng dần
    delay(time_delay);
  }
}
void MODE3() {  //Chế độ 3: sáng dồn đảo
  //int time_delay = 100;
  All_OFF();
  delay(time_delay);
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], ON);
    delay(time_delay);
  }
  All_OFF();
  // delay(time_delay);
  for (int i = 7; i >= 0; i--) {
    digitalWrite(LED[i], ON);
    delay(time_delay);
  }
}
void MODE4() {  //Chế độ 4: led đơn đuổi từ dưới lên
  //int time_delay = 100;
  All_OFF();
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], ON);  // sáng dần
    digitalWrite(LED[i - 1], OFF);
    delay(time_delay);
  }
}
void MODE5() {  //Chế độ 5: led đơn đuổi từ trên xuống
  //int time_delay = 100;
  All_OFF();
  for (int i = 7; i >= 0; i--) {
    digitalWrite(LED[i], ON);  // sáng dần
    digitalWrite(LED[i + 1], OFF);
    delay(time_delay);
  }
}
void MODE6() {  //Chế độ 6: led đơn đuổi đảo qua lại
  //int time_delay = 100;
  All_OFF();
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], ON);  // sáng dần
    digitalWrite(LED[i - 1], OFF);
    delay(time_delay);
  }
  for (int i = 7; i >= 0; i--) {
    digitalWrite(LED[i], ON);  // sáng dần
    digitalWrite(LED[i + 1], OFF);
    delay(time_delay);
  }
}
void MODE7() {  //Chế độ 7: led sáng luân phiên chẵn lẻ
  //int time_delay = 100;
  digitalWrite(LED[0], ON);
  digitalWrite(LED[1], OFF);
  digitalWrite(LED[2], ON);
  digitalWrite(LED[3], OFF);
  digitalWrite(LED[4], ON);
  digitalWrite(LED[5], OFF);
  digitalWrite(LED[6], ON);
  digitalWrite(LED[7], OFF);
  delay(time_delay);
  digitalWrite(LED[0], OFF);
  digitalWrite(LED[1], ON);
  digitalWrite(LED[2], OFF);
  digitalWrite(LED[3], ON);
  digitalWrite(LED[4], OFF);
  digitalWrite(LED[5], ON);
  digitalWrite(LED[6], OFF);
  digitalWrite(LED[7], ON);
  delay(time_delay);
}
void MODE8() {  //Chế độ 8: led sáng luân phiên chẵn lẻ 2 led
  //int time_delay = 100;
  digitalWrite(LED[0], ON);
  digitalWrite(LED[1], ON);
  digitalWrite(LED[2], OFF);
  digitalWrite(LED[3], OFF);
  digitalWrite(LED[4], ON);
  digitalWrite(LED[5], ON);
  digitalWrite(LED[6], OFF);
  digitalWrite(LED[7], OFF);
  delay(time_delay);
  digitalWrite(LED[0], OFF);
  digitalWrite(LED[1], OFF);
  digitalWrite(LED[2], ON);
  digitalWrite(LED[3], ON);
  digitalWrite(LED[4], OFF);
  digitalWrite(LED[5], OFF);
  digitalWrite(LED[6], ON);
  digitalWrite(LED[7], ON);
  delay(time_delay);
}
void MODE9() {  //Chế độ 9: led sáng luân phiên 4 led
  //int time_delay = 100;
  digitalWrite(LED[0], ON);
  digitalWrite(LED[1], ON);
  digitalWrite(LED[2], ON);
  digitalWrite(LED[3], ON);
  digitalWrite(LED[4], OFF);
  digitalWrite(LED[5], OFF);
  digitalWrite(LED[6], OFF);
  digitalWrite(LED[7], OFF);
  delay(time_delay);
  digitalWrite(LED[0], OFF);
  digitalWrite(LED[1], OFF);
  digitalWrite(LED[2], OFF);
  digitalWrite(LED[3], OFF);
  digitalWrite(LED[4], ON);
  digitalWrite(LED[5], ON);
  digitalWrite(LED[6], ON);
  digitalWrite(LED[7], ON);
  delay(time_delay);
}
void MODE10() {  //Chế độ 10
  //int time_delay = 100;
  All_OFF();
  delay(time_delay);
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], ON);
    delay(time_delay);
  }
  // All_OFF();
  delay(time_delay);
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], OFF);
    delay(time_delay);
  }
  delay(time_delay);
  for (int i = 7; i >= 0; i--) {
    digitalWrite(LED[i], ON);
    delay(time_delay);
  }
  // All_OFF();
  delay(time_delay);
  for (int i = 7; i >= 0; i--) {
    digitalWrite(LED[i], OFF);
    delay(time_delay);
  }
}

//C:\Users\Admin\AppData\Local\Temp\arduino\sketches\BB10693D29FD9065922F1B8C0E2EADA0