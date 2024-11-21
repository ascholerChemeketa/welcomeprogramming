while (true) {
  drawing.step();
  try {
    this_thread::sleep_for(chrono::milliseconds(1000 / 30));
  } catch (const system_error& e) {
    // do nothing
  }
}