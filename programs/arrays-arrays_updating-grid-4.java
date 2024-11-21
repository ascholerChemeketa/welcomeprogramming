private static void updateCell(Cell cell, int count) {
    if (cell.isOn()) {
        if (count &lt; 2 || count > 3) {
            cell.turnOff();
        }
    } else {
        if (count == 3) {
            cell.turnOn();
        }
    }
}