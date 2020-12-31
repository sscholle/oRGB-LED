# oRGB-LED Sketch

Red, Green and Blue LED strips can fade into different colours. Like a Rainbow,
but more BRILLIANT!

The Red, Green and Blue LEDs are switched on separately, very quickly, which gives
a trippy visual effect when the lights or the viewer moves. This can work well on
a spinning LED mount.

Main Behaviour:
- A color is calculated in continuous loops, using FADEAMNT and MAX/MIN BIRGHTNESS
- Each color starts at a different brightness, like a color wheel
- When a 'color' is output, the separate color channels are individually switched ON
- this results in less power consumption
- the visual effect looks stimulating
- the effect was tweaked to balance between least strobing and low power useage 
  
## Note
- Works best with PlatformIO