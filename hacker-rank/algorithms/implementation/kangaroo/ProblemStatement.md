https://www.hackerrank.com/challenges/kangaroo

So I handled this with math.

Given: Initial distances and velocities for kangaroo 1 and 2:  <b>x<sub>1</sub>,v<sub>1</sub>,x<sub>2</sub>,v<sub>2</sub></b>.
<br>
Let the distance for kangaroo 1 at any given time <b>t</b> be:
  <b>s<sub>1</sub>=x<sub>1</sub>+v<sub>1</sub>t</b>
  <br>
Let the distance for kangaroo 2 at any given time <b>t</b> be:
    <b>s<sub>2</sub>=x<sub>2</sub>+v<sub>2</sub>t</b>



Goal: Determine if there is a time <b>t</b> where the two distances <b>s<sub>1</sub>,s<sub>2</sub></b> are equal?

Let <b>z=s<sub>1</sub>=s<sub>2</sub></b>
<br><b>
z=x<sub>1</sub>+v<sub>1</sub>t
<br>
z=x<sub>2</sub>+v<sub>2</sub>t
<br>
x<sub>1</sub>+v<sub>1</sub>t=x<sub>2</sub>+v<sub>2</sub>t
<br>
x<sub>1</sub>-x<sub>2</sub>=v<sub>2</sub>t-v<sub>1</sub>t=(v<sub>2</sub>-v<sub>1</sub>)t
<br>
(x<sub>1</sub>-x<sub>2</sub>)/(v<sub>2</sub>-v<sub>1</sub>)=t
</b>

Plug in given values into this formula, if <b>t</b> is a positive integer, there is a time when they are at the same place at the same time.
