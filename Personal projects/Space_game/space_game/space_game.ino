// Space game project for Arduino Uno.
// Goals for this project is to create a game that is playable on a 16x2 LCD screen with one button.

#include <LiquidCrystal.h>
#define BUTTON_PIN 2

LiquidCrystal lcd(11, 9, 6, 5, 4, 3); // RS, E, D4, D5, D6, D7
int display_row = 0;
int spaceship_Y = 0;
int spaceship_X = 0;
int asteroid_Y = 1;
int asteroid_X = 16;
int index = 0;
int asteroid_speed = 4;
int game_points = 0;
bool game_over = false;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 200;

static byte space_ship_char[] = {
    B11000,
    B01000,
    B01100,
    B00111,
    B00111,
    B01100,
    B01000,
    B11000};

static byte asteroid_char[] = {
    B00000,
    B01100,
    B01110,
    B11111,
    B11111,
    B01110,
    B00110,
    B00000};

void print_spaceship(int row)
{
  lcd.createChar(0, space_ship_char);
  lcd.setCursor(0, row);
  lcd.write(byte(0));
}

void print_asteroid(int row)
{
  lcd.createChar(1, asteroid_char);
  lcd.setCursor(row, 0);
  lcd.write(byte(1));
}

void move_spaceship()
{

  while (!game_over)
  {
    if (digitalRead(2) == HIGH && (millis() - lastDebounceTime) > debounceDelay)
    {
      spaceship_Y = 1 - spaceship_Y;
      lastDebounceTime = millis();
    }
    // Päivitä asteroidin sijainti
    index++;
    if (index == asteroid_speed)
    {
      asteroid_X--; // Asteroidi liikkuu yhden askeleen
      index = 0;
    }
    if (asteroid_X < 0)
    {
      asteroid_X = 15; // Asteroidi palaa näytön oikeaan reunaan
      asteroid_Y = random(0, 2);
      asteroid_speed = random(1, 5);
      game_points++;
    }

    // Tyhjennä näyttö ja aseta spaceship ja asteroidi
    lcd.clear();
    lcd.setCursor(0, spaceship_Y);
    lcd.write(">"); // Spaceship
    lcd.setCursor(asteroid_X, asteroid_Y);
    lcd.write("*"); // Asteroidi
    if (game_points < 10)
    {
      lcd.setCursor(15, 0);
    }
    else if (game_points < 100)
    {
      lcd.setCursor(14, 0);
    }
    else
    {
      lcd.setCursor(13, 0);
    }
    lcd.print(game_points);
    delay(50);

    // Tarkista törmäys
    if (spaceship_Y == asteroid_Y && spaceship_X == asteroid_X)
    {
      game_over = true;
      // Flashing the asteroid
      for (int i = 0; i < 5; i++)
      {
        lcd.clear();
        lcd.setCursor(asteroid_X, asteroid_Y);
        lcd.write("*");
        delay(200);
        lcd.clear();
        lcd.setCursor(asteroid_X, asteroid_Y);
        lcd.write(" ");
        delay(200);
      }
    }
  }
  game_over_screen();
}

void game_over_screen()
{
  lcd.clear();
  lcd.setCursor(14, 0);
  lcd.print("Game over! Score:" + String(game_points));
  lcd.setCursor(14, 1);
  lcd.print("Press button to restart");
  while (digitalRead(2) == LOW)
  {
    delay(150);
    lcd.scrollDisplayLeft();
  }
  lcd.clear();
  spaceship_Y = 0;
  spaceship_X = 0;
  asteroid_Y = random(0, 2);
  asteroid_X = 16;
  index = 0;
  asteroid_speed = 4;
  game_points = 0;
  game_over = false;
}

void intro_screen()
{
  while (digitalRead(2) == LOW)
  {
    lcd.setCursor(0, 0);
    lcd.print("Welcome to Space");
    lcd.setCursor(0, 1);
    lcd.print("Press button to start");
  }
  lcd.clear();
}

void gameplay()
{
  // intro_screen();
  move_spaceship();
}

void setup()
{
  lcd.begin(16, 2);
  pinMode(BUTTON_PIN, INPUT);
  intro_screen();
}

void loop()
{
  gameplay();
}