String text = "";
for (int i = 0; i &lt; 10; i++) {
    String line = in.nextLine();        // new string
    text = text + line + '\n';    // two more strings
}
System.out.print("You entered:\n" + text);