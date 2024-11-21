void paint(Graphics g) override {
  for (const auto& dp : list) {
    dp.draw(g);
  }
}
