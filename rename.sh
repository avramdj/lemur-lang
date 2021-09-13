#!/bin/bash

p1='Avrlang'
q1='Lemur'
p2='avrlang'
q2='lemur'
p3='AVRLANG'
q3='LEMUR'

find $1 -type f -exec sed -i "s/$p1/$q1/g" {} +
find $1 -type f -exec sed -i "s/$p2/$q2/g" {} +
find $1 -type f -exec sed -i "s/$p3/$q3/g" {} +


find . -name "*$p1*" -exec rename "s/$p1/$q1/" {} \;
find . -name "*$p2*" -exec rename "s/$p2/$q2/" {} \;
find . -name "*$p3*" -exec rename "s/$p3/$q3/" {} \;
