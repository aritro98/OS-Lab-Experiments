#WAP in Shell Scipts to Find all Roots of a Quadratic Equation.
#!/bin/sh
read -p"Enter coefficent of x^2:" a
read -p"Enter coefficent of x:" b
read -p"Enter constant c:" c
d=$(($b*$b-4*$a*$c))
D=$(echo "sqrt ($d)" | bc -l)
echo $D
A=$(($a*2))
echo "Roots are (-$b-$D)/$A) and (-$b+$D)/$A)"
