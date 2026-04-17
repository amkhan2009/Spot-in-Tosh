#include <Arduino.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <WiFi.h>
#include <SpotifyEsp32.h>
#include <SPI.h>

// Screen pins – change the numbers to match your wiring
#define TFT_CS   1
#define TFT_RST  2
#define TFT_DC   3
#define TFT_SCLK 4
#define TFT_MOSI 5

// WiFi info
char* SSID = "CatchMeIfYouCan";
const char* PASSWORD = "I'm_not_gonna_tell_you_my_password";

// Spotify info from the developer dashboard
const char* CLIENT_ID = "faceb857f78e4b80aff2ae3b83089518";
const char* CLIENT_SECRET = "56dd7dd98b3742d695091d12254e1f6e";

String lastArtist;
String lastTrackname;

Spotify sp(CLIENT_ID, CLIENT_SECRET);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup() {
  Serial.begin(115200);

  // 1. Screen setup
  tft.initR(INITR_BLACKTAB);      // start the ST7735
  tft.setRotation(1);             // landscape
  Serial.println("TFT Initialized!");
  tft.fillScreen(ST77XX_BLACK);   // clear screen

  // 2. WiFi setup
  WiFi.begin(SSID, PASSWORD);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.printf("\nConnected!\n");

  // 3. Show IP on screen
  tft.setCursor(0, 0);
  tft.write(WiFi.localIP().toString().c_str());

  // 4. Spotify setup
  sp.begin();
  while (!sp.is_auth()) {
    sp.handle_client();   // do the auth handshake
  }
  Serial.println("Authenticated");
}

void loop() {

  // Ask Spotify what is playing
  String currentArtist = sp.current_artist_names();
  String currentTrackname = sp.current_track_name();
  bool playing = sp.is_playing(); // - my own addition

  // If the artist changed and is valid…
  if (lastArtist != currentArtist &&
      currentArtist != "Something went wrong" &&
      !currentArtist.isEmpty()) {

    tft.fillScreen(ST77XX_BLACK);     // clear the screen
    lastArtist = currentArtist;       // remember it
    Serial.println("Artist: " + lastArtist);

    tft.setCursor(10, 10);
    tft.write(lastArtist.c_str());
  }

  // If the track name changed and is valid…
  if (lastTrackname != currentTrackname &&
      currentTrackname != "Something went wrong" &&
      currentTrackname != "null") {

    lastTrackname = currentTrackname;          // remember it
    Serial.println("Track: " + lastTrackname);

    tft.setCursor(10, 40);
    tft.write(lastTrackname.c_str());
  }

    // Draw a simple status indicator at the top
  tft.fillRect(0, 0, 160, 10, ST77XX_BLACK);   // clear a thin strip at the top

  tft.setCursor(2, 1);
  if (playing) {
    tft.fillRect(0, 0, 160, 10, ST77XX_GREEN); // green bar if playing
    tft.setCursor(2, 1);
    tft.write("PLAYING");
  } else {
    tft.fillRect(0, 0, 160, 10, ST77XX_RED);   // red bar if paused/not playing
    tft.setCursor(2, 1);
    tft.write("PAUSED");
  }

  delay(2000);
}
