StringBuilder text = new StringBuilder();
for (int i = 0; i &lt; 10; i++) {
    String line = in.nextLine();
    text.append(line);
    text.append('\n');
}
System.out.print("You entered:\n" + text);