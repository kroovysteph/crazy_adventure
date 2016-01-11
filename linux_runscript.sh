#!/bin/bash

cd prog1lib/lib/;
make;
cd ../../;
echo ">> prog1lib successfully compiled!";

if [[ -s ./adventure ]] ; then
	rm adventure;
	echo "wurde geloescht";
fi

make adventure && ./adventure;
