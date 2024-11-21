public boolean equals(Time that) {
    final double DELTA = 0.001;
    return this.hour == that.hour
        &amp;&amp; this.minute == that.minute
        &amp;&amp; Math.abs(this.second - that.second) &lt; DELTA;
}