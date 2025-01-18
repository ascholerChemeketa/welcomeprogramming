void draw(Graphics* g) {         // Draw the entire grid
    for (auto& row : array) {    // For each row
        for (auto& cell : row) { // For each cell in a row
            cell.draw(g);        // Draw cell
        }
    }
}
