int redPin = 11;
int greenPin = 10;
int bluePin = 9;

int button = 4;

int buttonState = 0;
int lastButtonState = 0;

unsigned long previousMillis = 0;
unsigned long lastMillis = 0;

int mood = 0;

int x = 0;
int y = 0;
int z = 0;

int r = 0;
int g = 0;
int b = 0;

#define COMMON_ANODE

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(button, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop()
{
  unsigned long currentMillis = millis();

  content();

  buttonState = digitalRead(button);

  if (buttonState != lastButtonState) {
    mood++;
    lastMillis = currentMillis;
  }

  if (currentMillis - lastMillis >= 2000) {
    content();
  }
  else if (currentMillis - lastMillis >= 15000 && mood >= 100){
    sad();
  }
  else {
    if (mood <= 25 && mood > 0) {
      fear();
    }
    else if ( mood > 25 && mood <= 75) {
      anger();
    }
    else if (mood > 75) {
      happiness();
    }
  }
  lastButtonState = buttonState;
  Serial.println(mood);
}

void setColor(int red, int green, int blue)
{
#ifdef COMMON_ANODE
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
#endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void sad() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 300) {
    if (x < 15) {
      x++;
      previousMillis = currentMillis;
    }
    else {
      x = 0;
    }
  }

  if (x == 1 || x == 14) {
    setColor(0, 0, 102);
  }
  else if (x == 2 || x == 13) {
    setColor(0, 0, 128);
  }
  else if (x == 3 || x == 12) {
    setColor(0, 0, 153);
  }
  else if (x == 4 || x == 11) {
    setColor(0, 0, 179);
  }
  else if (x == 5 || x == 10) {
    setColor(0, 0, 204);
  }
  else if (x == 6 || x == 9) {
    setColor(0, 0, 230);
  }
  else if (x == 7 || x == 8) {
    setColor(0, 0, 255);
  }
}

void content() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > 200) {
    if (y < 9) {
      y++;
      previousMillis = currentMillis;
    }
    else {
      y = 0;
    }

    if (y == 1 || y == 8) {
      setColor(102, 0, 204);
    }
    else if (y == 2 || y == 7) {
      setColor(127, 0, 255);
    }
    else if (y == 3 || y == 6) {
      setColor(153, 51, 255);
    }
    else if (y == 4 || y == 5) {
      setColor(178, 102, 255);
    }
  }
}

void fear() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > 50) {
    r = random(150, 235);
    g = random(150, 235);
    previousMillis = currentMillis;
  }

  setColor(r, g, 0);
}

void happiness() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > 125) {
    if (z < 9) {
      z++;
      previousMillis = currentMillis;
    }
    else {
      z = 0;
    }

    if (z == 1 || z == 8) {
      setColor(0, 153, 0);
    }
    else if (z == 2 || z == 7) {
      setColor(0, 204, 0);
    }
    else if (z == 3 || z == 6) {
      setColor(0, 255, 0);
    }
    else if (z == 4 || z == 5) {
      setColor(51, 255, 51);
    }
  }
}

void anger() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > 50) {
    r = random(150, 235);
    previousMillis = currentMillis;
  }

  setColor(r, 0, 0);
}
