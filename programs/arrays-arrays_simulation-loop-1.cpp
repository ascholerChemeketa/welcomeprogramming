private
void mainloop() {
  while (true) {
    this->update();
    grid->repaint();
    this_thread::sleep_for(chrono::milliseconds(500));
  }
}
