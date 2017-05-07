#!/bin/bash

if [ ! -d "../externals/Catch" ]; then
  cd ../externals && git clone https://github.com/philsquared/Catch.git 
  cd -
fi


CMAKECOMMAND="cmake .."

$CMAKECOMMAND && make && tests/testunit



