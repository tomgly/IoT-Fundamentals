import processing.serial.*;
Serial myPort;
PImage logo;
int bgcolor = 0;

void setup() {
  size(1, 1);
  surface.setResizable(true);
  colorMode(HSB,225);
  logo = loadImage("https://www.sinclair.edu/www/includes/themes/wwwBootstrap4/images/sinclair-logo.png");
  surface.setSize(logo.width, logo.height);
  println("Available serial ports:");
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[2],9600);
}

void draw() {
  if (myPort.available() > 0) {
    bgcolor = myPort.read();
    println(bgcolor);
  }
  background(bgcolor, 255, 255);
  image(logo, 0, 0);
}
