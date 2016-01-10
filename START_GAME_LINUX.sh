#!/bin/bash

cd prog1lib/lib/;
make;
cd ../../;
echo ">> prog1lib successfully compiled!";
make adventure && ./adventure;
