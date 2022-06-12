#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

int val = 0;                         // По умолчанию диод не горит
const char *ssid = "Ardulogic";      // Название сети WiFi
const char *password = "1234567890"; // Пароль для подключения
ESP8266WebServer server(80);         // Создаем веб сервер на 80 порту

// Метод формирует стартовую страницу http://192.168.4.1
// Выводит в браузер текущее состояние диода и две кнопки
void handleRoot() {
  String s = (val) ? "<h1>LED On</h1>" : "<h1>LED Off</h1>";
  s += "<h2><a href=\"/led/on\">LED On</a> ";
  s += "<a href=\"/led/off\">LED Off</a></h2>";
  server.send(200, "text/html", s);
}

// Метод включения диода
void ledOn() {
  val = 1; // Включаем диод
  digitalWrite(BUILTIN_LED, val);
  // Перенаправление обратно на стартовую страницу
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

// Метод выключения диода
void ledOff() {
  val = 0; // Выключаем диод
  digitalWrite(BUILTIN_LED, val);
  // Перенаправление обратно на стартовую страницу
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

// Функция настройки. Выполняется один раз при запуске
void setup() {
  delay(1000);                 // Ждём секунду
  WiFi.softAP(ssid, password); // Создаём точку WiFi
  // Указываем по каким роутам какие методы запускать
  server.on("/", handleRoot);
  server.on("/led/on", ledOn);
  server.on("/led/off", ledOff);
  server.begin();
  // Диод по умолчанию выключен
  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED, val);
}

// Основной цикл программы
void loop() {
  // Ждём подключения
  server.handleClient();
}
