// set up the window frame
JFrame frame("Drawing");
frame.setDefaultCloseOperation(JFrame::EXIT_ON_CLOSE);
frame.add(&drawing);
frame.pack();
frame.setVisible(true);
return 0;
}