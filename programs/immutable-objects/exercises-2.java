String s = "((3 + 7) * 2)";
int count = 0;

for (int i = 0; i &lt; s.length(); i++) {
    char c = s.charAt(i);
    if (c == '(') {
        count++;
    } else if (c == ')') {
        count--;
    }
}

System.out.println(count);