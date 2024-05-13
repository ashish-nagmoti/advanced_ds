#!/bin/bash
echo "Enter the nnumber whose factorial is needed"
read n

fact=${n} 

for (( i = n-1; i>0;i-- ))
{
    fact=$((fact*i))
}

echo "The factorial of $n is $fact"