/****************************************************************************
 *       Copyright (C) 2017 Gaetano Mendola <mendola@gmail.com>             *
 * This work is free. You can redistribute it and/or modify it under the    *
 * terms of the Do What The Fuck You Want To Public License, Version 2,     *
 * as published by Sam Hocevar. See http://www.wtfpl.net/ for more details. *
 ****************************************************************************/


#include <iostream>

#include "units/units.h"

#include "catch.hpp"

TEST_CASE("First test", "[first test]") {
  uns::Length<float>   myLength(3.0);

  REQUIRE( sizeof(float) == sizeof(myLength));

  uns::Time<float>     myTime(3.4);
  uns::Velocity<float> myVelocity = myLength / myTime;

  REQUIRE( static_cast<float>(myVelocity) == static_cast<float>(myLength) / static_cast<float>(myTime) );

  uns::Length<float> myLength2 = myVelocity * myTime;

  REQUIRE( static_cast<float>(myLength2) == static_cast<float>(myLength) );

  uns::Length<float> myLength3 = myLength2 + myLength;

  REQUIRE( static_cast<float>(myLength3) == static_cast<float>(myLength2) + static_cast<float>(myLength) );
}

