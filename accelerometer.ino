    #include <Adafruit_CircuitPlayground.h>
    #include <Wire.h>
    #include <SPI.h>
    #define ROTATION_RATE   1000
      
    float X, Y, Z;
     
    // Define 10 colors here.
    // Must be 10 entries.
    // Use 0x000000 if you want a blank space.
    uint32_t colors[] = {
      0xFF0000,   
      0xFF5500,
      0xFFFF00,
      0x00FF00,
      0x0000FF,
      0xFF00FF,
      0x000000,
      0x000000,
      0x000000,
      0x000000
    };
     
    int colorIndex;
    int startIndex;
     
    void setup() {
      
      Serial.begin(9600);
      CircuitPlayground.begin();
           // Make it bright!
      CircuitPlayground.setBrightness(100);
     
      // Start at the beginning
      startIndex = 0;
    }
     
    void loop() {
       // Turn off all the NeoPixels
      CircuitPlayground.clearPixels();
      Z = CircuitPlayground.motionZ();
      Serial.println(Z);
      // Loop through and set pixels
      colorIndex = startIndex;
      for (int pixel=0; pixel<10; pixel++) {
        CircuitPlayground.setPixelColor(pixel, colors[colorIndex]);
        colorIndex++;
        if (colorIndex > 9) 
        colorIndex = 0;
      }
     
      // Increment start index into color array
      startIndex++;
     
      // Check value and reset if necessary
      if (startIndex > 9) 
      startIndex = 0; 
      
     

      if (Z < 2)
     delay(ROTATION_RATE);

     else if (Z < 3 && Z > 2)
     delay(ROTATION_RATE-200);

     else if (Z < 4 && Z > 3)
    delay(ROTATION_RATE-400);
     
    else if (Z < 5 && Z > 4)
    delay(ROTATION_RATE-600);
     
    else if (Z < 6 && Z > 5)
    delay(ROTATION_RATE-800);
     
    else if (Z < 20)
    delay(ROTATION_RATE-900);

     else if (Z>10)
   CircuitPlayground.clearPixels();
      
            // Wait a little bit so we don't spin too fast
      
    }
