#!/bin/sh

echo "Do you want to compile?"
read compile
if [ "$compile" = "y" ]; then
    make re
fi
echo "Press enter to proceed..."
read
./bomberman
if [ "$?" = "0" ]; then
    echo "Nailed it"
else
    echo "Ca a chie"; fi
echo "Do you wish to proceed?.."
read next
if [ "$next" = "y" -o "$next" = "\n" ]; then
    mv test.conf test_old.conf
    mv test2.conf test.conf
    ./bomberman
    if [ "$?" = "0" ]; then
	echo "Nailed it"
    else
	echo "Ca a chie"; fi
    mv test.conf test2.conf
    mv test_old.conf test.conf
fi
