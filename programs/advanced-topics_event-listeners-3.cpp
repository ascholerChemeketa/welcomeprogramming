void keyPressed(KeyEvent e) {
  switch (e.getKeyCode()) {
  case KeyEvent.VK_UP:
    dy = -5;
    break;
  case KeyEvent.VK_DOWN:
    dy = 5;
    break;
  case KeyEvent.VK_LEFT:
    dx = -5;
    break;
  case KeyEvent.VK_RIGHT:
    dx = 5;
    break;
  }
}