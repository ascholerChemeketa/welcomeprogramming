bool isOff() {
  return state == 0;
}

bool isOn() {
  return state == 1;
}

void turnOff() {
  state = 0;
}

void turnOn() {
  state = 1;
}