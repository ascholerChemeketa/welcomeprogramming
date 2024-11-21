int main() {
  // create some regular polygons
  RegularPolygon p1(3, 50, Color::GREEN);
  RegularPolygon p2(6, 50, Color::ORANGE);
  RegularPolygon p3(360, 50, Color::BLUE);

  // move them out of the corner
  p1.translate(100, 80);
  p2.translate(250, 120);
  p3.translate(400, 160);

  // create drawing, add polygons
  Drawing drawing(500, 250);
  drawing.add(&p1);
  drawing.add(&p2);
  drawing.add(&p3);

  // ... rest of main function
  return 0;
}